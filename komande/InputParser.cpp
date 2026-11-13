//
// Created by mladen on 13. 11. 2026..
//

#include "InputParser.h"
#include <sstream>

vector<string> parser(string s)
{
    stringstream ss(s);
    vector<string> inputParsed;
    string word;
    while (ss>>word)
    {
        inputParsed.push_back(word);
    }
    return inputParsed;
}