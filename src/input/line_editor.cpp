#include "line_editor.hpp"

#include <iostream>

std::string LineEditor::readLine(const std::string& prompt)
{
    std::cout << prompt;

    std::string line;
    std::getline(std::cin, line);

    return line;
}
