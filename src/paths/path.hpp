#pragma once

#include <filesystem>
#include <string>

bool isBuiltin(const std::string& cmd);

bool isExecutable(const std::filesystem::path& file);

std::string findExecutable(const std::string& cmd);
