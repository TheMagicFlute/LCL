#ifndef CONSTANTS_H
#define CONSTANTS_H

// Include the necessary header for std::string
#include <string>

/*
 * This file contains the constants used in the program.
 */

// Colors
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string RESET = "\033[0m";

// Special codes
const int ERR_CODE = -1;
const int END_CODE = 0;

// Modes
const int NORMAL_MODE = 0;
const int DEBUG_MODE = 1;

#endif // CONSTANTS_H
