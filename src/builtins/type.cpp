#include "builtins.hpp"
#include "../path/path.hpp"
#include <iostream>
#include <string>

using namespace std;


void handleType(const string& cmd)
{
    if(isBuiltin(cmd))
    {
        cout << cmd << " is a shell builtin" << endl;
        return;
    }

    string executablePath = findExecutable(cmd);

    if(executablePath.empty())
    {
        cout << cmd << ": not found" << endl;
    }
    else
    {
        cout << cmd << " is " << executablePath << endl;
    }
}
