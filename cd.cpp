//
// Created by mladen on 13. 11. 2026..
//

#include "cd.h"
#include <filesystem>
#include <iostream>

void changeDir(string givenPath)
{
    filesystem::path newPath;

    if (givenPath ==".")
    {
        newPath = filesystem::current_path();
    }
    else if (givenPath=="..")
    {
        newPath = filesystem::current_path().parent_path();
    }
    else
    {
        newPath = givenPath;
    }
    if (newPath.empty())
    {
        cerr<<"cd: No directory is given.\n";

    }

    error_code ec;
    filesystem::current_path(newPath,ec);
    if (ec)
    {
     cerr<<"cd: "<< ec.message()<<"\n";
    }
}
