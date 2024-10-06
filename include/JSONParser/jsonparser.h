#ifndef JSON_H
#define JSON_H

#include "exceptions.h"
#include <rapidjson/document.h>
#include <string>

#define VALIJSON_USE_EXCEPTIONS

class JSONParser {
public:
  JSONParser() = default;

  bool loadJSON(const std::string_view target_file, rapidjson::Document &JSONDocument);  
  bool validate(const std::string_view schema_file, const std::string_view target_file);

  bool disableExceptions();
  std::string getLastError() const;

private:
  bool enableExceptions = true;
  std::string lastError;

  rapidjson::Document loadDocument(const std::string_view target_file) const;
};

#endif