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

if (JSONparser.loadDocument("demofiles/schema.json", "demofiles/json.json",
                            JSONDocument)) {
// Handle success.
} else {
// Handle failure.
}
```

## Also see:
# The giants on whose shoulders we stand:
* [RapidJSON GitHub](https://github.com/Tencent/rapidjson/)
* [Valijson GitHub](https://github.com/tristanpenman/valijson/)
