#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <unordered_map>
#include <functional>

#include "komande/InputParser.h"
#include "komande/Execute.h"
#include "komande/cd.h"
#include "komande/pwd.h"
#include "komande/echo.h"
#include "komande/help.h"

using namespace std;

string getPathFromhome()
{
    string str = filesystem::current_path();
    return str.substr(str.find_first_not_of("/")+1);

}

int main()
{
    vector<string> parsedInput;
    const unordered_map<string, function<void()>> controls =
    {
        {"cd", [&](){changeDir(parsedInput.size()>1 ? parsedInput[1]:"");}},
        {"pwd",[&](){printWorkingDirectory();}},
        {"exite",[&](){exit(0);}},
        {"echo", [&](){echoText(parsedInput.size()>1 ? listALL(parsedInput) : "");}},
        {"help", [&](){help();}}

    };




    while (true)
    {
        cout<<"[~/"<<getPathFromhome()<<"]^";


        string input;
        getline(cin,input);

        parsedInput = parser(input);


        auto it = controls.find(parsedInput[0]);
        if (it !=controls.end())
        {
            it->second();
        }

        else
        {
            executeCommand(parsedInput);
        }

    }

}
