// ANSI4LIFE
const std::string CLEARSCR = "\033[H\033[J";
const std::string BOLD = "\033[1m";

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";

const std::string HEADER = BOLD + GREEN;
const std::string SUCCESS = BLUE;
const std::string FAILURE = RED;
const std::string RESET = "\033[0m";

// Strings used in the demos.
const std::string header = CLEARSCR + HEADER + "\nEnjoy this demo." + RESET;

const std::string d1Header =
    HEADER +
    "\n\nDemo 1: Load a schema-validated rapidjson document from a json file." +
    RESET;
const std::string d1Success = SUCCESS + "\nSuccessfuly loaded json:" + RESET;
const std::string d1Failure = FAILURE + "\nAn error occurred:" + RESET;
const std::string d1Footer = SUCCESS + "End of output." + RESET;
 
const std::string d2Header = HEADER + "\n\nDemo 2: Load an invalid schema with exceptions enabled." + RESET;
const std::string d2Failure = FAILURE + "\nAn exception occurred:" + RESET;
const std::string d2Footer = FAILURE + "End of output." + RESET;

const std::string d3Header = HEADER + "\n\nDemo 3: Load an invalid json file, no exceptions." + RESET;
const std::string d3Failure = FAILURE + "\nAn error occurred:" + RESET;
const std::string d3Footer = FAILURE + "End of output." + RESET;

const std::string d4Header = HEADER + "\n\nDemo 4: Load another invalid json file, no exceptions" + RESET;
const std::string d4Failure = FAILURE + "\nAn error occurred:" + RESET;
const std::string d4Footer = FAILURE + "End of output." + RESET;

const std::string footer = HEADER + "\nEnd of demo. Goodbye.";

// Demo functions obv.
void demo_1();
void demo_2();
void demo_3();
void demo_4();