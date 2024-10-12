// Mandatory include.
#include "jsonparser.h"

// Includes for demo.
#include "demostrings.inc"
#include <iostream>

// Demo functions.
void demo_start();
void demo_1();
void demo_2();
void demo_end();


// Run the demos.
int main() {
  demo_start();
  demo_1();
  demo_2();
  demo_end();

} // main


void demo_1() {
  // Demo 1: Load a schema-validated rapidjson document from a json file.
  std::cout << demo_1Header << std::endl;

  JSONParser JSONparser;
  rapidjson::Document JSONDocument;
  try {
    JSONparser.loadDocument("demofiles/schema.json", "demofiles/json.json",
                            JSONDocument);
  } catch (const JSONParserException &e) {
    std::cout << FAILURE << "An exception occured:\n";
    std::cout << e.what() << '\n';
    return;
  }

  // Success, print json.
  std::cout << demo_1Success << std::endl;

  int val = JSONDocument["exampleKey1"].GetInt();
  std::cout << val << std::endl;

  // End of demo 1.
  std::cout << demo1_Finish << std::endl;
}


void demo_2() {
  // Demo 2: Invalid schema.
  std::cout << demo_2Header << std::endl;

  JSONParser JSONparser;
  rapidjson::Document JSONDocument;
  try {
    JSONparser.loadDocument("demofiles/schema_invalid.json",
                            "demofiles/json.json", JSONDocument);
  } catch (const JSONParserException &e) {
    std::cout << FAILURE << "An exception occured:\n" + RESET;
    std::cout << e.what() << '\n';
  }

  // End of demo 2.
  std::cout << demo2_Finish << std::endl;
}

void demo_start() {
  // Start of demo.
  std::cout << header << std::endl;
}

void demo_end() {
  // End of demo.
  std::cout << footer << std::endl;
}