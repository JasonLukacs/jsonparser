std::string RESET = "\033[0m";
std::string HEADER = "\033[34m\033[1m";
std::string FOOTER = "\033[32m\033[1m";
std::string SUCCESS = "\033[32m";
std::string FAILURE = "\033[31m";

std::string demo_1Header = HEADER + "\nDemo: Succesful validation against schema:" + RESET;
std::string demo_2Header = HEADER + "\nDemo: Missing file:" + RESET;
std::string demo_3Header = HEADER + "\nDemo: Invalid schema:" + RESET;
std::string demo_4Header = HEADER + "\nDemo: Invalid json (1): value out of range:" + RESET;
std::string demo_5Header = HEADER + "\nDemo: Invalid json (2): missing key:" + RESET;
std::string demo_6Header = HEADER + "\nDemo: Succesful validation against schema:" + RESET;
