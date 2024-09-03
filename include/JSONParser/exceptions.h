#include <string>


class JSONParserException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};