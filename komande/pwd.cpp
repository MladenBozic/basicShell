//
// Created by mladen on 13. 11. 2026..
//

#include "pwd.h"
#include <filesystem>
#include <iostream>
#include <string>

using namespace std;

void printWorkingDirectory() {
    string absolutePath;
    absolutePath = filesystem::absolute(filesystem::current_path());
    cout<<absolutePath<<"\n";



}

