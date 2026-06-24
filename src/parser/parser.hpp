#pragma once

#include <string>
#include "../models/parsed_command.hpp"

ParsedCommand parseCommand(const std::string& line);
