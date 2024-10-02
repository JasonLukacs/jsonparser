#include <rapidjson/error/en.h>
#include <rapidjson/istreamwrapper.h>
#include <valijson/adapters/rapidjson_adapter.hpp>
#include <valijson/schema.hpp>
#include <valijson/schema_parser.hpp>
#include <valijson/utils/rapidjson_utils.hpp>
#include <valijson/validation_results.hpp>
#include <valijson/validator.hpp>

#include "jsonparser.h"
#include <fstream>

bool JSONParser::validate(const std::string &schema_file,
                          const std::string &target_file) const {
  // Load files into rapidjson documents.
  rapidjson::Document schemaDocument = getDocument(schema_file);
  rapidjson::Document targetDocument = getDocument(target_file);

  // Parse the json schema into an internal schema format.
  valijson::Schema schema;
  valijson::SchemaParser parser;
  valijson::adapters::RapidJsonAdapter schemaDocumentAdapter(schemaDocument);
  try {
    parser.populateSchema(
        schemaDocumentAdapter,
        schema);
  } catch (std::runtime_error &e) { // catch what is thrown by valijson.
    std::string cwd = std::filesystem::current_path().string();
    std::string error_message =
        "Error parsing schema. Library valijson returns: \n";
    error_message += e.what();
    throw JSONParserException(error_message);
  }

  // Perform validation
  valijson::Validator validator(valijson::Validator::kStrongTypes);
  if (valijson::ValidationResults results; !validator.validate(
          schema, valijson::adapters::RapidJsonAdapter(targetDocument),
          &results)) {

    std::string error_message = "\nJSON cannot be validated against schema:\n";

    // Iterate through validation errors and gather detailed information
    valijson::ValidationResults::ValidationResults::Error error;
    while (results.popError(error)) {
      // Construct a more informative context string
      std::string context;
      for (const std::string &pathElement : error.context) {
        context += "/" + pathElement;
      }
      error_message += "\nContext: " + context + ": ";
      error_message += error.description;
    }

    // Include schema and target file paths for better debugging
    error_message += "\n\nUsing schema file: ";
    error_message += schema_file;
    error_message += "\nUsing JSON file: ";
    error_message += target_file;
    error_message += "\n";

    throw JSONParserException(error_message);
  }
  return true;
}

rapidjson::Document JSONParser::getDocument(std::string_view file_name) const {
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
    // RapidJSON only provides offset of the error.
    // Calculate line number of the error for a useful error message.
    ifs.seekg(0);
    size_t lineNumber = 1;
    size_t errorOffset = document.GetErrorOffset();

    while (!ifs.eof() && ifs.tellg() < errorOffset) {
      auto c = static_cast<char>(ifs.get());
      if (c == '\n') {
        lineNumber++;
      }
    }

    std::string error_message = "\n\nError on line ";
    error_message += std::to_string(lineNumber);
    error_message += ": ";

    error_message += rapidjson::GetParseError_En(document.GetParseError());

    error_message += "\nwhile reading ";
    error_message += file_name;

    error_message += ", opened from: ";
    std::string cwd = std::filesystem::current_path().string();
    error_message += cwd;
    error_message += ".\n\n";

    throw JSONParserException(error_message);
  }

  return document;
}