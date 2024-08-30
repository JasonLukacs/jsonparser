#ifndef JSON_H
#define JSON_H

#include <rapidjson_adapter.hpp>
#include <rapidjson_utils.hpp>
#include <schema.hpp>
#include <schema_parser.hpp>
#include <validation_results.hpp>
#include <validator.hpp>

using valijson::Schema;
using valijson::SchemaParser;
using valijson::Validator;
using valijson::ValidationResults;
using valijson::adapters::RapidJsonAdapter;

#define VALIJSON_USE_EXCEPTIONS

class JSONParser {
public:
    JSONParser() = default;

    bool JSONValidate(const std::string& schema_file, const std::string& target_file) const;
    bool GetJSONDocument(std::string_view target_file) const;
    const std::string& getError() const;

private:
    std::string parser_error;

};

#endif