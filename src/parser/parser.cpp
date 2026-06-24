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
            result.outputFile = tokens[i + 1];
            break;
        }

        result.args.push_back(tokens[i]);
    }

    return result;
}
