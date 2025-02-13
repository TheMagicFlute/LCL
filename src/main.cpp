#include "./LCL.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printUsage();
        return 1;
    }
    inputFileName = argv[1];
    outputFileName = getFileName(inputFileName) + ".cpp";
    currentArgumentIndex = 2;
    while (currentArgumentIndex < argc)
    {
        std::string arg = parseNextArgument();
        if (arg == "-h" || arg == "--help")
        {
            printUsage();
            return 0;
        }
        else if (arg == "-v" || arg == "--version")
        {
            displayVersion();
            return 0;
        }
        else if (arg == "-o" || arg == "--output")
        {
            if (currentArgumentIndex < argc)
            {
                outputFileName = parseNextArgument();
            }
            else
            {
                printERR("missing output file name");
                return 1;
            }
        }
        else
        {
            printERR("unrecognized command-line argument: '" + arg + "';");
        }
    }
    return 0;
}