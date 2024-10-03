# jsonparser 
## A simple json parser / validator using rapidjson and valijson

## Usage:
Clone the repo:  
    git clone https://github.com/JasonLukacs/jsonparser.git
Initialize the submodules:  
    git submodule update --init
__Note: The submodules contain pretty large nested submodules which are not required,__
__so avoid (git clone) --recurse-submodules and (git submodule update --init) --recursive__

Include the header:  
```cpp
#include "jsonparser.h"
```

Perform a simple validation:  
```cpp
JSONParser parser;
bool validation_result = parser.validate("schema.json", "json.json");

if (validation_result) {
    // Succes
} else {
    // Failure
}
```

## Also see:
* [RapidJSON GitHub](https://github.com/Tencent/rapidjson/)
* [Valijson GitHub](https://github.com/tristanpenman/valijson/)