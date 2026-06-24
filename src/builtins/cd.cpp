#include "builtins.hpp"

#include <filesystem>
#include <cstdlib>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

void handleCd(string pathStr)
{
    if(pathStr == "~")
    {
        pathStr = getenv("HOME");
    }

    fs::path p = pathStr;

    if(!fs::exists(p))
    {
        cout << "cd: " << pathStr
             << ": No such file or directory" << endl;
        return;
    }

    if(!fs::is_directory(p))
    {
        cout << "cd: " << pathStr
             << ": No such file or directory" << endl;
        return;
    }

    fs::current_path(p);
}
