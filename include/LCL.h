#ifndef LCL_H
#define LCL_H

#define PROGRAM_NAME "LCL"
#define VERSION "v0.0.1"
#define PLATFORM "pc-windows-g++"
#define COMPILE_TIME __TIMESTAMP__
// #define GIT_COMMIT "12345678"

// include standard libraries
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// define functions
void displayVersion();
void printUsage();
inline std::string parseNextArgument();

inline void printWARN(const std::string message);
inline void printERR(const std::string message);

inline bool hasFileExtension(const std::string filename);
std::string getFileName(std::string filename);
std::string getFileExtension(std::string filename);

// define global variables
int currentArgumentIndex = 0;
std::string inputFileName = "";
std::string outputFileName = "";

// define colors of output text
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string RESET = "\033[0m";

// realisation of functions
/**
 * Print the usage message
 */
void printUsage()
{
    std::cout << "Usage: " << __argv[0] << " <source file> [options]\n";
    std::cout << "Options:\n";
    std::cout << "  -h, --help       Show this help message\n";
    std::cout << "  -v, --version    Show version information\n";
    std::cout << "  -o, --output     Custom output file name\n";
    return;
}

/**
 * Display the version information
 */
void displayVersion()
{
    std::cout << PROGRAM_NAME << " " << VERSION << " for " << PLATFORM << "\n";
    std::cout << "Built on " << COMPILE_TIME << "\n";
    return;
}

/**
 * Parse the next command line argument
 * @return the next argument
 */
inline std::string parseNextArgument()
{
    return __argv[currentArgumentIndex++];
}

/**
 * Print a warning message
 * @param message the message to print
 */
inline void printWARN(const std::string message)
{
    std::cout << PROGRAM_NAME << ": ";
    std::cout << YELLOW << "Warning: " << RESET;
    std::cout << message << std::endl;
    return;
}

/**
 * Print an error message
 * @param message the message to print
 */
inline void printERR(const std::string message)
{
    std::cout << PROGRAM_NAME << ": ";
    std::cout << RED << "Error: " << RESET;
    std::cout << message << std::endl;
    return;
}

/**
 * Check if a file has an extension
 * @param filename the name of the file
 * @return true if the file has an extension
 */

inline bool hasFileExtension(const std::string filename)
{
    return filename.find_last_of(".") != std::string::npos;
}

/**
 * Get the file name from a path
 * @param filename the name of the file
 * @return the file name
 */
std::string getFileName(std::string filename)
{
    if (hasFileExtension(filename))
    {
        size_t pos = filename.find_last_of(".");
        return filename.substr(0, pos);
    }
    return filename;
}

/**
 * Get the file extension from a path
 * @param filename the name of the file
 * @return the file extension
 */
std::string getFileExtension(std::string filename)
{
    size_t pos;
    if (hasFileExtension(filename))
    {
        pos = filename.find_last_of(".");
        filename = filename.substr(pos + 1);
    }
    else
    {
        pos = filename.find_last_of("/\\");
        if (pos != std::string::npos)
        {
            filename = filename.substr(pos + 1);
        }
    }
    return filename;
}


#endif // LCL_H
