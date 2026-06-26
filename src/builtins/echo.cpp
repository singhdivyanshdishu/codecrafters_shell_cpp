#include "builtins.hpp"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

static void writeOutput(
    const string& output,
    const ParsedCommand& cmd)
{
    if(cmd.redirectStdout)
    {
        ofstream file(cmd.stdOutFile);
        file << output;
    }
    else
    {
        cout << output;
    }
}

void handleEcho(const ParsedCommand& cmd)
{
    string output;

    for(size_t i = 1; i < cmd.args.size(); i++)
    {
        if(i > 1)
        {
            output += " ";
        }

        output += cmd.args[i];
    }

    output += '\n';
    if(cmd.redirectStderr){
        ofstream errFile(cmd.stdErrFile);
    }

    writeOutput(output, cmd);
}
