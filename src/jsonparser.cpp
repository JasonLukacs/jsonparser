#include <rapidjson/error/en.h>
#include <rapidjson/istreamwrapper.h>
#include <valijson/adapters/rapidjson_adapter.hpp>
#include <valijson/schema.hpp>
#include <valijson/schema_parser.hpp>
#include <valijson/utils/rapidjson_utils.hpp>
#include <valijson/validation_results.hpp>
#include <valijson/validator.hpp>

#include "jsonparser.h"
#include <filesystem>
#include <fstream>

bool JSONParser::loadDocument(const std::string_view schemaFile,
                              const std::string_view jsonFile,
                              rapidjson::Document &JSONDocument) {

  // Load files into rapidjson documents.
  rapidjson::Document schemaDocument;
  rapidjson::Document targetDocument;
  try {
    loadFile(schemaFile, schemaDocument);
    loadFile(jsonFile, targetDocument);
  } catch (const JSONParserException &e) {
    lastError = e.what();
    if (enableExceptions) {
      throw JSONParserException(lastError);
    } else {
      return false;
    }
  }

  // Parse the json schema into an internal schema format.
  valijson::Schema schema;
  valijson::SchemaParser parser;
  valijson::adapters::RapidJsonAdapter schemaDocumentAdapter(schemaDocument);
  try {
    parser.populateSchema(schemaDocumentAdapter, schema);
  } catch (std::runtime_error &e) { // catch what is thrown by valijson.
    std::string error_message =
        "Error parsing schema. Library valijson returns: \n";
    error_message += e.what();
    if (enableExceptions) {
      throw JSONParserException(error_message);
    } else {
      lastError = error_message;
      return false;
    }
  }

  // Perform validation
  valijson::Validator validator(valijson::Validator::kStrongTypes);
  if (valijson::ValidationResults results; !validator.validate(
          schema, valijson::adapters::RapidJsonAdapter(targetDocument),
          &results)) {
    
    // Failure
    std::string error_message =
        "\nError - File cannot be validated against schema: ";

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
    error_message += schemaFile;
    error_message += "\nUsing JSON file:   ";
    error_message += jsonFile;
    error_message += "\n";

    if (enableExceptions) {
      throw JSONParserException(error_message);
    } else {
      lastError = error_message;
      return false;
    }
  }

  // Success
  JSONDocument = std::move(targetDocument);
  return true;
}


bool JSONParser::loadFile(const std::string_view file_name,
                          rapidjson::Document &JSONDocument) const {

  if (!std::filesystem::exists(file_name)) {
    std::string error_message = "\n\nError - file not found: ";
    error_message += file_name;
    throw JSONParserException(error_message);
  }

  // Cap file size.
  if (std::filesystem::file_size(file_name) > 1048576) {
    std::string error_message = "\n\nError - file larger than 10MB: ";
    error_message += file_name;
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

    std::string error_message = "\n\nFile cannot be parsed: ";
    error_message += file_name;
    error_message += ".\nError on line  ";
    error_message += std::to_string(lineNumber);
    error_message += ": ";
    error_message += rapidjson::GetParseError_En(document.GetParseError());
    error_message += "\n"; // zoek

    throw JSONParserException(error_message);
  }

  JSONDocument = std::move(document);
  return true;
}


bool JSONParser::disableExceptions() {
  enableExceptions = false;

  return true;
}


std::string JSONParser::getLastError() const { return lastError; }