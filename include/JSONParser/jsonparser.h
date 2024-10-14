#ifndef JSONPARSER_H
#define JSONPARSER_H

#include "exceptions.h"
#include <rapidjson/document.h>
#include <string>

class JSONParser {
public:
  JSONParser() = default;

  bool loadDocument(const std::string_view schemaFile,
                    const std::string_view jsonFile,
                    rapidjson::Document &JSONDocument);
  bool enableExceptions(bool enable);
  std::string getLastError() const;

private:
  bool useExceptions = false;
  std::string lastError;

  bool loadFile(const std::string_view target_file,
                rapidjson::Document &JSONDocument) const;
};

#endif