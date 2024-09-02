#ifndef JSON_H
#define JSON_H

#include <string>

#include <rapidjson/document.h>

#include "exceptions.h"

#define VALIJSON_USE_EXCEPTIONS

class JSONParser {
public:
    JSONParser() = default;

    bool JSONValidate(const std::string& schema_file, const std::string& target_file) const;
    rapidjson::Document GetJSONDocument(std::string_view target_file) const;

};

#endif