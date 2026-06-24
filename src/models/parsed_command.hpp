#pragma once

#include <string>
#include <vector>

struct ParsedCommand
{
    std::vector<std::string> args;
    bool redirectStdout = false;
    std::string outputFile;
};
