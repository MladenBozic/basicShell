//
// Created by mladen on 13. 11. 2026..
//

#include "cd.h"
#include <filesystem>
#include <unistd.h>
#include <iostream>

void changeDir(string givenPath)
{
    filesystem::path newPath;

    if (givenPath ==".")
    {
        return;
    }
    else if (givenPath=="..")
    {
        newPath = filesystem::current_path().parent_path();
    }
    else
    {
        newPath = filesystem::absolute(givenPath);
        return;
    }
    if (newPath.empty())
    {
        cerr<<"cd: No parent directory.\n";
        return;
    }
    if (chdir(newPath.c_str()) != 0)
    {
        perror("cd");
    }

}
