#include "tokenizer.hpp"
#include <string>
#include <vector>


using namespace std;


vector<string> tokenize(const string& line)
{
    vector<string> tokens;
    string current;

    bool inSingleQuotes = false;
    bool inDoubleQuotes = false;

    for(size_t i = 0; i < line.size(); i++)
    {
        char ch = line[i];

        // Backslash outside quotes
        if(!inSingleQuotes && !inDoubleQuotes && ch == '\\')
        {
            if(i + 1 < line.size())
            {
                current += line[++i];
            }
            continue;
        }

        // Backslash inside double quotes
        if(inDoubleQuotes && ch == '\\')
        {
            if(i + 1 < line.size())
            {
                char next = line[i + 1];

                if(next == '"' || next == '\\')
                {
                    current += next;
                    i++;
                }
                else
                {
                    current += '\\';
                }
            }
            else
            {
                current += '\\';
            }

            continue;
        }

        if(ch == '\'' && !inDoubleQuotes)
        {
            inSingleQuotes = !inSingleQuotes;
            continue;
        }

        if(ch == '"' && !inSingleQuotes)
        {
            inDoubleQuotes = !inDoubleQuotes;
            continue;
        }

        if(ch == ' ' && !inSingleQuotes && !inDoubleQuotes)
        {
            if(!current.empty())
            {
                tokens.push_back(current);
                current.clear();
            }
            continue;
        }

        current += ch;
    }

    if(!current.empty())
    {
        tokens.push_back(current);
    }

    return tokens;
}
