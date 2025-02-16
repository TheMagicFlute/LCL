#include "./LCL.h"

int currentArgumentIndex = 0;
int mode = DEBUG_MODE;
std::string inputFileName = "";
std::string outputFileName = "";

int main(int argc, char *argv[])
{
    // If no arguments are passed, print usage
    if (argc == 1)
    {
        printUsage();
        return ERROR_EXIT_CODE;
    }
    inputFileName = parseNextArgument();
    outputFileName = getFileName(inputFileName) + ".cpp";
    // Parse arguments
    while (currentArgumentIndex < argc)
    {
        std::string arg = parseNextArgument();
        if (arg == "-h" || arg == "--help")
        {
            printUsage();
            return NORMAL_EXIT_CODE;
        }
        else if (arg == "-v" || arg == "--version")
        {
            displayVersion();
            return NORMAL_EXIT_CODE;
        }
        else if (arg == "-o" || arg == "--output")
        {
            if (currentArgumentIndex < argc)
            {
                outputFileName = parseNextArgument();
                logMessage("The filename is " + outputFileName);
                if (!isFile(outputFileName))
                {
                    printERR("The filename '" + outputFileName + "' is invalid.");
                    printUsage();
                    return ERROR_EXIT_CODE;
                }
            }
            else
            {
                printERR("Missing output file name.");
                return ERROR_EXIT_CODE;
            }
        }
        else
        {
            printERR("Unrecognized command-line argument: '" + arg + "'.");
            printUsage();
            return ERROR_EXIT_CODE;
        }
    }
    return NORMAL_EXIT_CODE;
}
