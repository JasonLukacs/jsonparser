// Mandatory include.
#include "jsonparser.h"

// Includes for demo.
#include "demo.h"
#include <iostream>


int main() {
  std::cout << header << std::endl;
  demo_1(); // Demo 1: Load a schema-validated rapidjson document from a json
            // file.
  demo_2(); // Demo 2: Load an invalid schema with exceptions enabled.
  demo_3(); // Demo 3: Load an invalid json file, no exceptions.
  demo_4(); // Demo 4: Load another invalid json file, no exceptions.
  std::cout << footer << std::endl;
} // main


void demo_1() {
  /***********************************************************************/
  /* Demo 1: Load a schema-validated rapidjson document from a json file.*/
  /***********************************************************************/
  std::cout << d1Header << std::endl;

  JSONParser JSONparser;
  rapidjson::Document JSONDocument;

  if (JSONparser.loadDocument("demofiles/schema.json", "demofiles/json.json",
                              JSONDocument)) {
    std::cout << d1Success << std::endl;
    std::cout << JSONDocument["exampleKey1"].GetString() << std::endl;
    std::cout << JSONDocument["exampleKey2"].GetInt() << std::endl;
  } else {
    std::cout << d1Failure << std::endl;
    std::cout << JSONparser.getLastError() << '\n';
  }

  std::cout << d1Footer << std::endl;
}


void demo_2() {
  /***********************************************************************/
  /* Demo 2: Load an invalid schema with exceptions enabled.             */
  /***********************************************************************/
  std::cout << d2Header << std::endl;

  JSONParser JSONparser;
  rapidjson::Document JSONDocument;

  JSONparser.enableExceptions(true);

  try {
    JSONparser.loadDocument("demofiles/schema_invalid.json",
                            "demofiles/json.json", JSONDocument);
  } catch (const JSONParserException &e) {
    std::cout << d2Failure << std::endl;
    std::cout << e.what() << '\n';
  }
  // Handle success.

  std::cout << d2Footer << std::endl;
  /***********************************************************************/
}


void demo_3() {
  /***********************************************************************/
  /* Demo 3: Load an invalid json file, no exceptions.                   */
  /***********************************************************************/
  std::cout << d3Header << std::endl;

  JSONParser JSONparser;
  rapidjson::Document JSONDocument;

  if (JSONparser.loadDocument("demofiles/schema.json",
                              "demofiles/json_invalid_1.json", JSONDocument)) {
    // Handle success.
  } else {
    std::cout << d3Failure << std::endl;
    std::cout << JSONparser.getLastError() << '\n';
  }

  std::cout << d3Footer << std::endl;
}


void demo_4() {
  /***********************************************************************/
  /* Demo 4: Load another invalid json file, no exceptions.                   */
  /***********************************************************************/
  std::cout << d4Header << std::endl;

  JSONParser JSONparser;
  rapidjson::Document JSONDocument;

  if (JSONparser.loadDocument("demofiles/schema.json",
                              "demofiles/json_invalid_2.json", JSONDocument)) {
    // Handle success.
  } else {
    std::cout << d4Failure << std::endl;
    std::cout << JSONparser.getLastError() << '\n';
  }

  std::cout << d4Footer << std::endl;
}