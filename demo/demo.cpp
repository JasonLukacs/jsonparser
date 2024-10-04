#include "jsonparser.h"
#include <iostream>


void Example_1(const std::string &schemaFile, const std::string &jsonFile);
void Example_2(const std::string &schemaFile, const std::string &jsonFile);


int main() {
  Example_1(); // Validation against schema, exceptions enabled (default).
  Example_2(); // Validation against schema, exceptions disabled.

  // End of demo.
  std::cout << "\nEnd of demo. Goodbye." << std::endl;
  return 0;
}


void Example_1(const std::string &schemaFile, const std::string &jsonFile) {
  // Example 1: Validation against schema, exceptions enabled (default)
  try {
    JSONParser JSONparser;
    JSONparser.validate(schemaFile, jsonFile);
  } catch (const JSONParserException &e) {
    std::cout << "An exception was thrown:\n";
    std::cout << e.what() << std::endl;
    return;
  }
  std::cout << "Succes." << std::endl;
}


void Example_2(const std::string &schemaFile, const std::string &jsonFile) {
  // Example 2: Validation against schema, exceptions disabled.
  JSONParser JSONparser;
  JSONparser.disableExceptions();

  if (bool validation_result = JSONparser.validate(schemaFile, jsonFile)) {
    std::cout << "Succes." << std::endl;
  } else {
    std::cout << "Validation failed. Error:\n" << std::endl;
    std::cout << JSONparser.getLastError() << std::endl;
  }
}