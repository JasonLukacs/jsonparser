#include "jsonparser.h"

// Includes for demo
#include "demostrings.inc"
#include <iostream>


// Basic usage is demonstrated in the following functions:
void validate(const std::string &schemaFile, const std::string &jsonFile);
void validateNoExceptions(const std::string &schemaFile,
                          const std::string &jsonFile);


// Show example output in various use cases:
int main() {
  // Succesful validation against schema.
  std::cout << demo_1Header << std::endl;
  validate("bin/demofiles/schema.json", "bin/demofiles/json.json");

  // Missing file.
  std::cout << demo_2Header << std::endl;
  validate("bin/demofiles/nofile.json", "bin/demofiles/json.json");

  // Invalid schema.
  std::cout << demo_3Header << std::endl;
  validate("bin/demofiles/schema_invalid.json", "bin/demofiles/json.json");

  // Invalid json (1), exceptions disabled.
  std::cout << demo_4Header << std::endl;
  validateNoExceptions("bin/demofiles/schema.json",
                       "bin/demofiles/json_invalid_1.json");

  // Invalid json (2), exceptions disabled.
  std::cout << demo_5Header << std::endl;
  validateNoExceptions("bin/demofiles/schema.json",
                       "bin/demofiles/json_invalid_2.json");

  // End of demo.
  std::cout << FOOTER << "\nEnd of demo. Goodbye." << std::endl;
  return 0;
} // main


// Validation against schema, exceptions enabled (default).
void validate(const std::string &schemaFile, const std::string &jsonFile) {
  try {
    JSONParser JSONparser;
    JSONparser.validate(schemaFile, jsonFile);
  } catch (const JSONParserException &e) {
    std::cout << FAILURE << "An exception was thrown:" << RESET;
    std::cout << e.what() << std::endl;
    return;
  }
  std::cout << SUCCESS << "Validation succesful." << std::endl;
}


// Validation against schema, exceptions disabled.
void validateNoExceptions(const std::string &schemaFile,
                          const std::string &jsonFile) {
  JSONParser JSONparser;
  JSONparser.disableExceptions();

  if (bool validation_result = JSONparser.validate(schemaFile, jsonFile)) {
    std::cout << SUCCESS << "Validation succesful." << std::endl;
  } else {
    std::cout << FAILURE << "Validation failed:" << RESET << std::endl;
    std::cout << JSONparser.getLastError() << std::endl;
  }
}