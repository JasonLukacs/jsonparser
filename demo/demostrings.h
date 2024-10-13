const std::string BOLD = "\033[1m";

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";

const std::string HEADER = BOLD + GREEN;
const std::string SUCCESS = BLUE;
const std::string FAILURE = RED;
const std::string RESET = "\033[0m";


const std::string header = BOLD + GREEN + "\nEnjoy this demo." + RESET;

const std::string demo_1Header =
    HEADER +
    "\n\nDemo 1: Load a schema-validated rapidjson document from a json file." +
    RESET;
const std::string demo_1_Success = SUCCESS + "\nSuccessfuly loaded json:" + RESET;
const std::string demo_1_Failure = FAILURE + "\nAn error occurred:" + RESET;
const std::string demo_1_Finish = SUCCESS + "\nEnd of output." + RESET;
 
const std::string demo_2_Header = HEADER + "\n\nDemo 2: Load an invalid schema with exceptions enabled." + RESET;
const std::string demo_2_Failure = FAILURE + "\nAn exception occurred:" + RESET;
const std::string demo_2_Finish = FAILURE + "\nEnd of output." + RESET;

const std::string demo_3_Header = HEADER + "\n\nDemo 3: Load an invalid json file, no exceptions." + RESET;
const std::string demo_3_Failure = FAILURE + "\nAn error occurred:" + RESET;
const std::string demo_3_Finish = FAILURE + "\nEnd of output." + RESET;

const std::string demo_4_Header = HEADER + "\n\nDemo 4: Load another invalid json file, no exceptions" + RESET;
const std::string demo_4_Failure = FAILURE + "\nAn error occurred:" + RESET;
const std::string demo_4_Finish = FAILURE + "\nEnd of output." + RESET;

const std::string footer = BOLD + GREEN + "\nEnd of demo. Goodbye.";