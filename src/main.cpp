#include <iostream>
#include <string>

#include "parser/parser.hpp"
#include "builtins/builtins.hpp"
#include "executor/executor.hpp"

using namespace std;

int main()
{
    cout << unitbuf;
    cerr << unitbuf;

    while(true)
    {
        cout << "$ ";

        string str;
        getline(cin, str);

        if(str.empty())
        {
            continue;
        }

        if(str == "exit")
        {
            break;
        }

        ParsedCommand cmd = parseCommand(str);

        if(cmd.args.empty())
        {
            continue;
        }

        if(cmd.args[0] == "echo")
        {
            handleEcho(cmd);
        }
        else if(str.substr(0, 5) == "type ")
        {
            handleType(str.substr(5));
        }
        else if(str == "pwd")
        {
            handlePwd();
        }
        else if(str.substr(0, 2) == "cd")
        {
            handleCd(str.substr(3));
        }
        else
        {
            executeExternalCommand(cmd);
        }
    }

    return 0;
}
