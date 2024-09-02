/**
 * @file
 *
 * @brief Demonstrates basic JSON functionality using valijson and rapidjson.
 *
 */
#include <iostream>

#include "exceptions.h"
#include "utils.h"
#include "jsonparser.h"


int main() {
    // Using example schema in /schema.
    // Using example files in /config.

    bool validation_result = false;
    
    try
    {
        JSONParser JSONparser;
        validation_result = JSONparser.JSONValidate("../schema/example_schema.json", "../config/example_json.json");
    }
    catch(const JSONParserException& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    

    if (validation_result) {
        std::cout << "Succes." << std::endl;
    } else {
        std::cout << "Failure." << std::endl;
    }

    std::cout << "\nEnd of demo. Goodbye." << std::endl;

    return 1;
}
