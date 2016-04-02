/**
 * @file   ParserClass.cpp
 * @brief  Implematation of the command line parser.
 * @author See the command `git blame` for precise informations on the author
 */

#include <regex>
#include "ParserClass.h"

ParserClass::ParserClass()
{
    aMinLenght = 0;
    aMaxLenght = 10;
}

ParserClass::ParserClass(int pArgNumber, char* pCommandLine[])
{
    aArgNumber = pArgNumber;
    aCommandLine = pCommandLine;
};

void ParserClass::setCommmandLine(char* pCommandLine[])
{
    aCommandLine = pCommandLine;
}

bool ParserClass::parse()
{
    if (aArgNumber > 1)
    {
        aZipFileName = std::string(aCommandLine[1]);

        for (int i = 2; i < aArgNumber; i++)
        {
            if (aCommandLine[i] == "-l")
            {
                i++;
                std::string lValue = std::string(aCommandLine[i]);
                std::regex lRegex("(\\d+)-(\\d+)");
                std::smatch lLimits;

                if(std::regex_match(lValue, lLimits, lRegex))
                {
                    aMinLenght = atoi(lLimits[1]);
                    aMaxLenght = atoi(lLimits[2]);
                }
                else
                {
                    aMaxLenght = atoi(aCommandLine[i]);
                }
            }
            else
            {
                showHelp();
            }
        }
    }
}

void ParserClass::showHelp()
{
    printf("BruteForceForever helps you bruteforce a zip file.\n\n"
            "Usage :  bbf <file_name> [option]\n"
            "file_name    -  The zip file to bruteforce\n"
            "Options: \n"
            "  -h | --help -  Shows help.\n"
            "  -l          -  Set lenght limit to the password.\n"
            "                 10 to set max lenght to 10, 3-10 to set a lenght between 3 and 10.");
}