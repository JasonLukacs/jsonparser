# jsonparser 
Wrapping rapidjson and valijson:  
Load a schema validated rapidjson document in one function call.  

## Build:  
Clone the repo:  
```console
git clone https://github.com/JasonLukacs/jsonparser.git  
```
  
Initialize the submodules:  
```console
git submodule update --init
```
  
_Note: The submodules contain pretty large nested submodules which are not required,  
so you may want to avoid --recurse-submodules / --recursive._
  
Build and run example program ``` demo```.

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
} else {
  // Handle failure.
}
```

By default, exceptions are disabled.
To check for success you can do something like:
```console
#include "jsonparser.h"

JSONParser parser;
rapidjson::Document myDocument;

if (parser.loadDocument("schema.json", "json.json", myDocument)) {
  // Success:
  std::cout << myDocument["exampleKey1"].GetString() << std::endl;
  std::cout << myDocument["exampleKey2"].GetInt() << std::endl;
} else {
  // Failure:
  std::cout << parser.getLastError() << '\n';
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
  std::cout << e.what() << '\n';
}
// Handle success.

```

# Also see:
The giants on whose shoulders we stand:
* [RapidJSON GitHub](https://github.com/Tencent/rapidjson/)
* [Valijson GitHub](https://github.com/tristanpenman/valijson/)
