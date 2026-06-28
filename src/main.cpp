#include "completion/completion.hpp"
#include "input/line_editor.hpp"
#include "parser/parser.hpp"
#include "builtins/builtins.hpp"
#include "executor/executor.hpp"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << unitbuf;
    cerr << unitbuf;

    LineEditor lineEditor;

    // Register Readline completion callback.
    initializeCompletion();

    while (true)
    {
        string str = lineEditor.readLine("$ ");

        ParsedCommand cmd = parseCommand(str);

        if (cmd.args.empty())
        {
            continue;
        }

        if (cmd.args[0] == "echo")
        {
            handleEcho(cmd);
        }
        else if (cmd.args[0] == "type")
        {
            handleType(cmd.args.size() > 1 ? cmd.args[1] : "");
        }
        else if (cmd.args[0] == "pwd")
        {
            handlePwd();
        }
        else if (cmd.args[0] == "cd")
        {
            handleCd(cmd.args.size() > 1 ? cmd.args[1] : "");
        }
        else if (cmd.args[0] == "exit")
        {
            break;
        }
        else
        {
            executeExternalCommand(cmd);
        }
    }

    return 0;
}
