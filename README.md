## jsonparser 
A simple json parser / validator using rapidjson and valijson.

### Usage:
* Clone the repo:  
    git clone https://github.com/JasonLukacs/jsonparser.git  
  
* Initialize the submodules:  
    git submodule update --init
  
_Note: The submodules contain pretty large nested submodules which are not required,_  
_so you may want to avoid --recurse-submodules / --recursive._
  
Study, build and run example program ``` demo.cpp```:
```console
cd build
make
cd bin
./demo
```

Basic usage boils down to:
```console
#include "jsonparser.h"

JSONParser JSONparser;
rapidjson::Document JSONDocument;

if (JSONparser.loadDocument("schema.json", "json.json", JSONDocument)) {
  // Handle success.
} else {
  // Handle failure.
}
```

By default, exceptions are disabled.
To check for success you can do something like:
```console
#include "jsonparser.h"

JSONParser JSONparser;
rapidjson::Document JSONDocument;

if (JSONparser.loadDocument("schema.json", "json.json", JSONDocument)) {
  // Success:
  std::cout << JSONDocument["exampleKey1"].GetString() << std::endl;
  std::cout << JSONDocument["exampleKey2"].GetInt() << std::endl;
} else {
  // Failure:
  std::cout << JSONparser.getLastError() << '\n';
}
```

Alternatively, you can enable exceptions and do something like:
```console
#include "jsonparser.h"

JSONParser JSONparser;
rapidjson::Document JSONDocument;

JSONparser.enableExceptions(true);

try {
  JSONparser.loadDocument("schema.json", "json.json", JSONDocument);
} catch (const JSONParserException &e) {
  // Failure.
  std::cout << e.what() << '\n';
}
// Handle success.

```

# Also see:
## The giants on whose shoulders we stand:
* [RapidJSON GitHub](https://github.com/Tencent/rapidjson/)
* [Valijson GitHub](https://github.com/tristanpenman/valijson/)
