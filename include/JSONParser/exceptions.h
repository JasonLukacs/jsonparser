#ifndef JSONPARSER_EXCEPTIONS_H
#define JSONPARSER_EXCEPTIONS_H

#include <string>

class JSONParserException : public std::runtime_error {
public:
  using std::runtime_error::runtime_error;
};

#endif