# jsonparser  

Wrapping rapidjson and valijson:  
Load a schema validated rapidjson document in one call.  

## Build

Clone the repo and initialize the submodules:  

```console
git clone https://github.com/JasonLukacs/jsonparser.git  
cd jsonparser
git submodule update --init
```

_Note: The submodules contain pretty large nested submodules which are not required,  
so you may want to avoid --recurse-submodules / --recursive._
  
Build and run example program ```demo```.

  Using make:

  ```console
  cd build
  cmake ..
  make
  ```

  Using ninja:

  ```console
  cd build
  cmake -G Ninja ..
  ninja
  ```

  Executable and demo JSON files are in /build/bin:
  
  ```console
  cd bin
  ./demo
  ```

## Basic usage

Boils down to:

```console
#include "jsonparser.h"

JSONParser parser;
rapidjson::Document myDocument;

if (parser.loadDocument("schema.json", "json.json", myDocument)) {
  // Handle success.
      std::string key1 = myDocument["exampleKey1"].GetString();
      int key2 = myDocument["exampleKey2"].GetInt();
} else {
  // Handle failure.
  std::string errorMessage = parser.getLastError();
}
```

Alternatively, you can enable exceptions and do something like:

```console
#include "jsonparser.h"

JSONParser parser;
rapidjson::Document myDocument;

parser.enableExceptions(true);

try {
  parser.loadDocument("schema.json", "json.json", myDocument);
} catch (const JSONParserException &e) {
  // Failure.
  std::string errorMessage = e.what();
}
// Handle success.
std::string key1 = myDocument["exampleKey1"].GetString();
int key2 = myDocument["exampleKey2"].GetInt();

```

## Also see  

The giants on whose shoulders we stand:

* [RapidJSON GitHub](https://github.com/Tencent/rapidjson/)
* [Valijson GitHub](https://github.com/tristanpenman/valijson/)
