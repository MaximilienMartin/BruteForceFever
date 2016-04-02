/**
 * @file   ParserClass.h
 * @brief  Definition of the command line parser.
 * @author See the command `git blame` for precise informations on the author
 */
#pragma once

#include <string>

class ParserClass {
public:
    ParserClass();
    ParserClass(int pArgNumber, char* pCommandLine[]);

    void setCommmandLine(char* pCommandLine[]);

    bool parse();
    void showHelp();

private:
    int aArgNumber;
    char* aCommandLine[];

    std::string aZipFileName;
    int aMinLenght;
    int aMaxLenght;
};

