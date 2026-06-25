#pragma once

#include <string>
#include <vector>

struct ParsedCommand
{
    std::vector<std::string> args;
    bool redirectStdout = false;
    std::string stdOutFile;
    bool redirectStderr = false;
    std::string stdErrFile;
};
