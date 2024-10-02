#ifndef JSON_H
#define JSON_H

#include "exceptions.h"

#include <rapidjson/document.h>

#include <string>

#define VALIJSON_USE_EXCEPTIONS

class JSONParser {
public:
  JSONParser() = default;

  bool validate(const std::string &schema_file,
                const std::string &target_file) const;
  rapidjson::Document getDocument(std::string_view target_file) const;
};

#endif