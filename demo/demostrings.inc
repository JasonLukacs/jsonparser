std::string BOLD = "\033[1m";

std::string RED = "\033[31m";
std::string GREEN = "\033[32m";
std::string BLUE = "\033[34m";

std::string HEADER = BOLD + BLUE;
std::string SUCCESS = BLUE;
std::string FAILURE = RED;
std::string RESET = "\033[0m";


std::string header = BOLD + GREEN + "\nEnjoy this demo." + RESET;
std::string footer = BOLD + GREEN + "\nEnd of demo. Goodbye.";


std::string demo_1Header =
    HEADER +
    "\nDemo 1: Load a schema-validated rapidjson document from a json file." +
    RESET;
std::string demo_1Success = SUCCESS + "\nSuccessfuly loaded json:" + RESET;
std::string demo_1Failure = FAILURE + "\nAn error occurred" + RESET;
std::string demo1_Finish = SUCCESS + "\nEnd of output." + RESET;
 
std::string demo_2Header = HEADER + "\nDemo 2: Load an invalid schema with exceptions enabled." + RESET;
std::string demo2_Finish = FAILURE + "\nEnd of output." + RESET;

