// Mandatory include.
#include "jsonparser.h"

// Includes for demo.
#include "demostrings.h"
#include <iostream>


int main() {
  std::cout << header << std::endl;

  /***********************************************************************/
  /* Demo 1: Load a schema-validated rapidjson document from a json file.*/
  /***********************************************************************/
  std::cout << demo_1Header << std::endl;

  JSONParser JSONparser;
  rapidjson::Document JSONDocument;
  if (JSONparser.loadDocument("demofiles/schema.json", "demofiles/json.json",
                              JSONDocument)) {
    std::cout << demo_1Success << std::endl;
    std::cout << JSONDocument["exampleKey1"].GetString() << std::endl;
    std::cout << JSONDocument["exampleKey2"].GetInt() << std::endl;
  } else {
    std::cout << demo_1Failure << std::endl;
    std::cout << JSONparser.getLastError() << '\n';
  }

  std::cout << demo1_Finish << std::endl;
  /***********************************************************************/


  /***********************************************************************/
  /* Demo 2: Load an invalid schema with exceptions enabled.             */
  /***********************************************************************/
  std::cout << demo_2Header << std::endl;

  JSONparser.enableExceptions(true);

  try {
    JSONparser.loadDocument("demofiles/schema_invalid.json",
                            "demofiles/json.json", JSONDocument);
  } catch (const JSONParserException &e) {
    std::cout << demo_2Failure << std::endl;
    std::cout << e.what() << '\n';
  }

  std::cout << demo2_Finish << std::endl;
  /***********************************************************************/

  std::cout << footer << std::endl;
} // main