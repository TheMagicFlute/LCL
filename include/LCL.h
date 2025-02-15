#ifndef LCL_H
#define LCL_H

#define PROGRAM_NAME "LCL"
#define VERSION "v0.0.1"
#define PLATFORM "pc-windows-g++"
#define COMPILE_TIME __TIMESTAMP__

// Standard libraries
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <chrono>
#include <ctime>

// Constants header
#include "./constants.h"

// Function declarations
void logMessage(const std::string &message);
std::string getCurrentTime();
void displayVersion();
void printUsage();
std::string parseNextArgument();
void printWARN(const std::string &message);
void printERR(const std::string &message);
bool hasFileExtension(const std::string &filename);
std::string getFileName(const std::string &filename);
std::string getFileExtension(const std::string &filename);
bool isFile(const std::string &filename);

// Global variables
extern int currentArgumentIndex;
extern int mode;
extern std::string inputFileName;
extern std::string outputFileName;

/**
 * @brief Log a message to the console if the debug mode is enabled.
 * @param message The message to log.
 */
inline void logMessage(const std::string &message)
{
    if (mode == DEBUG_MODE)
    {
        std::cout << CYAN << "DEBUG " << getCurrentTime() << " " << message << RESET << "\n";
    }
}

/**
 * @brief Get the current time as a string in the format "HH:MM:SS".
 * @return The current time as a string.
 */
inline std::string getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm *local_time = std::localtime(&now_time);
    std::ostringstream oss;
    oss << std::put_time(local_time, "%H:%M:%S");
    return oss.str();
}

/**
 * @brief Print the usage message.
 */
void printUsage()
{
    std::cout << "Usage: " << __argv[0] << " <source file> [options]\n";
    std::cout << "Options:\n";
    std::cout << "  -h, --help       Show this help message\n";
    std::cout << "  -v, --version    Show version information\n";
    std::cout << "  -o, --output     Custom output file name\n";
}

/**
 * @brief Print an error message.
 * @param message The message to print.
 */
inline void printERR(const std::string &message)
{
    std::cout << PROGRAM_NAME << ": ";
    std::cout << RED << "ERROR: " << RESET;
    std::cout << message << std::endl;
}

/**
 * @brief Display the version information.
 */
void displayVersion()
{
    std::cout << PROGRAM_NAME << " " << VERSION << " for " << PLATFORM << "\n";
    std::cout << "Built on " << COMPILE_TIME << "\n";
}

/**
 * @brief Parse the next command line argument.
 * @return The next argument.
 */
inline std::string parseNextArgument()
{
    logMessage("currentArgumentIndex: " + std::to_string(currentArgumentIndex));
    return __argv[currentArgumentIndex++];
}

/**
 * @brief Print a warning message.
 * @param message The message to print.
 */
inline void printWARN(const std::string &message)
{
    std::cout << PROGRAM_NAME << ": ";
    std::cout << YELLOW << "WARNING: " << RESET;
    std::cout << message << std::endl;
}

/**
 * @brief Check if a file has an extension.
 * @param filename The name of the file.
 * @return True if the file has an extension.
 */
inline bool hasFileExtension(const std::string &filename)
{
    return filename.find_last_of(".") != std::string::npos && filename.find_last_of(".") != filename.size() - 1;
}

/**
 * @brief Get the file name from a path.
 * @param filename The name of the file.
 * @return The file name.
 */
std::string getFileName(const std::string &filename)
{
    if (hasFileExtension(filename))
    {
        size_t pos = filename.find_last_of(".");
        return filename.substr(0, pos);
    }
    return filename;
}

/**
 * @brief Get the file extension from a path.
 * @param filename The name of the file.
 * @return The file extension.
 */
std::string getFileExtension(const std::string &filename)
{
    size_t pos;
    if (hasFileExtension(filename))
    {
        pos = filename.find_last_of(".");
        return filename.substr(pos + 1);
    }
    else
    {
        pos = filename.find_last_of("/\\");
        if (pos != std::string::npos)
        {
            return filename.substr(pos + 1);
        }
    }
    return filename;
}

/**
 * @brief Check if a file exists.
 * @param filename The name of the file.
 * @return True if the file exists, false otherwise.
 */
bool isFile(const std::string &filename)
{
    if (hasFileExtension(filename) && filename.substr(0, filename.find_last_of(".")) != "")
    {
        return true;
    }
    return false;
}

#endif // LCL_H
