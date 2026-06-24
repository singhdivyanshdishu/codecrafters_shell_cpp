#pragma once

#include "../models/parsed_command.hpp"
#include <string>
using namespace std;

void handleEcho(const ParsedCommand& cmd);

void handlePwd();

void handleCd(string pathStr);
void handleType(const string& cmd);
