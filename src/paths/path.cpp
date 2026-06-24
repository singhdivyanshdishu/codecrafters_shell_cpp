#include "path.hpp"

#include <filesystem>
#include <sstream>
#include <cstdlib>

using namespace std;
namespace fs = std::filesystem;

bool isBuiltin(const string& cmd)
{
    return cmd == "echo" ||
           cmd == "exit" ||
           cmd == "type" ||
           cmd == "pwd"  ||
           cmd == "cd";
}

bool isExecutable(const fs::path& file)
{
    auto perms = fs::status(file).permissions();

    return
        ((perms & fs::perms::owner_exec) != fs::perms::none) ||
        ((perms & fs::perms::group_exec) != fs::perms::none) ||
        ((perms & fs::perms::others_exec) != fs::perms::none);
}

string findExecutable(const string& cmd)
{
    char* pathEnv = getenv("PATH");

    if(pathEnv == nullptr)
        return "";

    string path(pathEnv);
    string dir;

    stringstream ss(path);

    while(getline(ss, dir, ':'))
    {
        fs::path candidate = fs::path(dir) / cmd;

        if(fs::exists(candidate) &&
           isExecutable(candidate))
        {
            return candidate.string();
        }
    }

    return "";
}
