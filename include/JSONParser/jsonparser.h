#ifndef JSON_H
#define JSON_H

#include "exceptions.h"
#include <rapidjson/document.h>
#include <string>

#define VALIJSON_USE_EXCEPTIONS

class JSONParser {
public:
  JSONParser() = default;

  rapidjson::Document getDocument(std::string_view target_file) const;
  bool validate(const std::string &schema_file, const std::string &target_file);

  bool disableExceptions();
  std::string getLastError() const;

private:
  bool enableExceptions = true;
  std::string lastError;
};

#endif