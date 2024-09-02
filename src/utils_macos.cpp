#include <iostream>
#include <fstream>
#include <vector>

#include "exceptions.h"
#include "utils.h"


bool JSONParserUtils::Silence_cerr() {
    std::cerr.rdbuf(nullptr);

    return true;
}

bool JSONParserUtils::Unsilence_cerr() {
    std::cerr.rdbuf(std::cout.rdbuf());

    return true;
}
