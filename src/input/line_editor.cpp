#include "line_editor.hpp"

#include <readline/readline.h>

#include <cstdlib>
#include <string>

std::string LineEditor::readLine(const std::string& prompt)
{
    char* buffer = readline(prompt.c_str());

    // Handle EOF (Ctrl+D)
    if (buffer == nullptr)
    {
        return "";
    }

    std::string line(buffer);

    free(buffer);

    return line;
}
