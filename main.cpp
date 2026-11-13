#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include "InputParser.h"
#include "Execute.h"
#include "cd.h"
#include "pwd.h"
#include "echo.h"
#include "help.h"

using namespace std;

string getPathFromhome()
{
    string str = filesystem::current_path();
    return str.substr(str.find_first_not_of("/")+1);

}

int main()
{
    while (true)
    {
        cout<<"[~/"<<getPathFromhome()<<"]^";


        string input;
        getline(cin,input);


        vector<string> parsedInput = parser(input);
        if (parsedInput[0] == "cd")
        {
            changeDir(parsedInput.size() > 1 ? parsedInput[1] : "");
        }
        if (parsedInput[0] == "pwd")
        {
            printWorkingDirectory();
        }

        if (parsedInput[0]=="exit")
        {
            exit(0);
        }
        if (parsedInput[0]=="echo")
        {
            echoText(parsedInput.size()>1 ? parsedInput[1]:"");
        }

        if (parsedInput[0]=="help")
        {
            help();
        }

        else
        {
            executeCommand(parsedInput);
        }

    }

}
