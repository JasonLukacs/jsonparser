#include <json.h>

bool JSONParser::JSONValidate(const std::string& schema_file, const std::string& target_file) const {
    // Load the schema from file.
    rapidjson::Document schemaDocument;
    if (!valijson::utils::loadDocument(schema_file, schemaDocument)) {
        std::cerr << "Failed to load schema document." << std::endl;
        return false;
    }

    // Load the JSON to be validated from file.
    rapidjson::Document targetDocument;
    if (!valijson::utils::loadDocument(target_file, targetDocument)) {
        std::cerr << "Failed to load target document." << std::endl;
        return false;
    }

    // Parse the json schema into an internal schema format
    Schema schema;
    SchemaParser parser;
    RapidJsonAdapter schemaDocumentAdapter(schemaDocument);
    try {
        parser.populateSchema(schemaDocumentAdapter, schema);
    } catch (std::runtime_error& e) {
        std::cerr << "Failed to parse schema: " << e.what() << std::endl;
        return false;
    }

    // Perform validation
    Validator validator(Validator::kStrongTypes);
    ValidationResults results;
    RapidJsonAdapter targetDocumentAdapter(targetDocument);
    if (!validator.validate(schema, targetDocumentAdapter, &results)) {
        std::cerr << "Validation failed." << std::endl;
        ValidationResults::Error error;
        unsigned int errorNum = 1;
        while (results.popError(error)) {
            std::string context;
            //std::vector<std::string>::iterator itr = error.context.begin();
            auto itr = error.context.begin();
            for (; itr != error.context.end(); itr++) {
                context += *itr;
            }

            std::cerr << "Error #" << errorNum << std::endl
                      << "  context: " << context << std::endl
                      << "  desc:    " << error.description << std::endl;
            ++errorNum;
        }
        return false;
    }

    return true;
}


bool JSONParser::GetJSONDocument(std::string_view target_file) const {

    return true;
}


const std::string& JSONParser::getError() const {
    return parser_error;
}