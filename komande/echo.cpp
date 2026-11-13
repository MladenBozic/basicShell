//
// Created by mladen on 13. 11. 2026..
//

#include "echo.h"
#include <iostream>

void echoText(string message) {
    cout<<message<<"\n";
}

string listALL(vector<string> parsedInput) {
    string str="";
    for(int i=1;i<parsedInput.size();i++)
    {
        str += parsedInput[i]+" ";
    }
    return str;
}
