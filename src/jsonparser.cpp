#include <iostream>
#include <fstream>
#include <vector>

#include <rapidjson/istreamwrapper.h>
#include <rapidjson/error/en.h>

#include <valijson/utils/rapidjson_utils.hpp>
#include <valijson/adapters/rapidjson_adapter.hpp>
#include <valijson/schema.hpp>
#include <valijson/schema_parser.hpp>
#include <valijson/validator.hpp>
#include <valijson/validation_results.hpp>

#include "JSONParser/jsonparser.h"
#include "JSONParser/utils.h"

using valijson::Schema;
using valijson::SchemaParser;
using valijson::Validator;
using valijson::ValidationResults;
using valijson::adapters::RapidJsonAdapter;


bool JSONParser::JSONValidate(const std::string& schema_file, const std::string& target_file) const {
    // Load files into rapidjson documents.
    rapidjson::Document schemaDocument = GetJSONDocument(schema_file);
    rapidjson::Document targetDocument = GetJSONDocument(target_file);

    // Parse the json schema into an internal schema format.
    Schema schema;
    SchemaParser parser;
    RapidJsonAdapter schemaDocumentAdapter(schemaDocument);
    try {
        parser.populateSchema(schemaDocumentAdapter, schema); // Questionable error handling in valijson function.
    } catch (std::runtime_error& e) {  // catch what is thrown by valijson.
        std::string cwd = std::filesystem::current_path().string();
        std::string error_message = "Error parsing schema. Library valijson returns: \n";
        error_message += e.what();
        throw JSONParserException(error_message);
    }

    // Perform validation
    Validator validator(Validator::kStrongTypes);
    ValidationResults results;
    RapidJsonAdapter targetDocumentAdapter(targetDocument);

    if (!validator.validate(schema, targetDocumentAdapter, &results)) {  // Questionable error handling in valijson function.
        std::string error_message = "JSON cannot be validated against schema.\n";
        error_message += "Using schema file: ";
        error_message += schema_file;
        error_message += "\nUsing JSON file: ";
        error_message += target_file;
        error_message += "\nError:\n ";
        
        ValidationResults::Error error;
        while (results.popError(error)) {
            std::string context;
            auto itr = error.context.begin();
            for (; itr != error.context.end(); itr++) {
                context += *itr;
            }

            error_message += "\n";
            error_message += error.description;
        }

         throw JSONParserException(error_message);
    }

    return true;
}


rapidjson::Document JSONParser::GetJSONDocument(std::string_view file_name) const {
    bool fileExists;
    fileExists = std::filesystem::exists(file_name);
    if (!fileExists) {
        std::string error_message = "\n\nError: File not found: ";
        error_message += file_name;
        error_message += "\n\nSearching in: ";
        std::string cwd = std::filesystem::current_path().string();
        error_message += cwd;
        error_message += "\n\n";
        throw JSONParserException(error_message);
    }

    std::ifstream ifs(file_name);
    rapidjson::IStreamWrapper isw(ifs);

    rapidjson::Document document;
    document.ParseStream(isw);

    if (document.HasParseError()) {
        // Calculate line number where error occurs.
        ifs.seekg(0);
        std::vector<size_t> newlineOffsets;
        size_t currentLine = 1;
        while (!ifs.eof()) {
            auto c = static_cast<char>(ifs.get());
            if (c == '\n') {
                newlineOffsets.push_back(static_cast<size_t>(ifs.tellg()) - 1);
                currentLine++;
            }
        }
        size_t lineNumber = std::upper_bound(newlineOffsets.begin(), newlineOffsets.end(), document.GetErrorOffset()) - newlineOffsets.begin();

        // Throw exception with verbose error message.
        std::string error_message = "\n\nError on line ";
        error_message += std::to_string(lineNumber);
        error_message += " while reading ";
        error_message += file_name;
        error_message += ":\n\n****\n";
        error_message += rapidjson::GetParseError_En(document.GetParseError());
        
        error_message += ":\n****\n\nFile opened from: ";
        std::string cwd = std::filesystem::current_path().string();
        error_message += cwd;
        error_message += "\n\n";

        throw JSONParserException(error_message);
    }

    return document;
}