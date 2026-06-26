#include "parser.hpp"
#include "tokenizer.hpp"

using namespace std;

ParsedCommand parseCommand(const string& line)
{
    vector<string> tokens = tokenize(line);

    ParsedCommand result;

    for(size_t i = 0; i < tokens.size(); i++)
    {
        if(tokens[i] == ">" || tokens[i] == "1>")
        {
            result.redirectStdout = true;
            result.appendStdout = false;
            result.stdOutFile = tokens[i + 1];
            break;
        }
        else if(tokens[i] == ">>" || tokens[i] == "1>>"){
            result.redirectStdout = true;
            result.appendStdout = true;
            result.stdOutFile = tokens[i+1];
            break;
        }
        else if(tokens[i] == "2>"){
            result.redirectStderr = true;
            result.appendStderr = false;
            result.stdErrFile = tokens[i+1];
            break;
        }

        result.args.push_back(tokens[i]);
    }

    return result;
}
