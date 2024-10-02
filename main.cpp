/**
 * @file
 *
 * @brief Demonstrates basic JSON functionality using valijson and rapidjson.
 *
 */
#include <iostream>

#include "jsonparser.h"

int main() {
  bool validation_result = false;

  try {
    JSONParser JSONparser;
    validation_result = JSONparser.validate("../schema/example_schema.json",
                                                "../config/example_json.json");
  } catch (const JSONParserException &e) {
    std::cerr << e.what() << '\n';
    return 0;
  }

  if (validation_result) {
    std::cout << "Succes." << std::endl;
  } else {
    std::cout << "Failure." << std::endl;
  }

  std::cout << "\nEnd of demo. Goodbye." << std::endl;

  return 0;
}
