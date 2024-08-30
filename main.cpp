/**
 * @file
 *
 * @brief Demonstrates basic JSON functionality using valijson and rapidjson.
 *
 */

#include "json.h"

void Validate(const std::string& file_name);
const JSONParser JSONparser;

int main() {
    // Using example schema in /schema.
    // Using example files in /config.

    std::cout << "Validating example 1: ";
    Validate("../config/example_json1.json");
    std::cout << "Validating example 2: ";
    Validate("../config/example_json2.json");

    std::cout << std::endl << "End of demo. Goodbye." << std::endl;
    return 1;
}

void Validate(const std::string& file_name) {
    if (bool validation_result = JSONparser.JSONValidate("../schema/example_schema.json", file_name)) {
        std::cout << "Succes." << std::endl;
    } else {
        std::cout << "Failure." << std::endl;
    }
}