#include <iostream>
#include <string>
#include<vector>
#include <sstream>
#include <filesystem>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;
namespace fs = std::filesystem;

bool isBuiltin(const string& cmd)
{
    return cmd == "echo" ||
           cmd == "exit" ||
           cmd == "type" ||
           cmd == "pwd";
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

        if(fs::exists(candidate) && isExecutable(candidate))
        {
            return candidate.string();
        }
    }

    return "";
}

void handleType(const string& cmd)
{
    if(isBuiltin(cmd))
    {
        cout << cmd << " is a shell builtin" << endl;
        return;
    }

    string executablePath = findExecutable(cmd);

    if(executablePath.empty())
    {
        cout << cmd << ": not found" << endl;
    }
    else
    {
        cout << cmd << " is " << executablePath << endl;
    }
}

void executeExternalCommand(const string& line) {
    stringstream ss(line);
    string word ;
    vector<string> tokens;
    while(ss >> word){
        tokens.push_back(word);
    }
    string path = findExecutable(tokens[0]);
    if(path.empty()){
        cout << tokens[0] << ": command not found" << endl;
        return;
    }
    vector<char*> argv;

    for(auto& token:tokens){
        argv.push_back(token.data());
    }
    argv.push_back(nullptr);

    pid_t pid=fork();

    if(pid == 0 ){
        execv(path.c_str(),argv.data());
        exit(1);
    }
    else
{
    waitpid(pid, nullptr, 0);
}


}

void handlePwd(){
    cout<< fs::current_path().string() << endl;
}

int main()
{
    cout << unitbuf;
    cerr << unitbuf;

    while(true)
    {
        cout << "$ ";

        string str;
        getline(cin, str);
        if(str.empty())
        {
            continue;
        }

        if(str == "exit")
        {
            break;
        }

        else if(str.substr(0, 5) == "echo ")
        {
            cout << str.substr(5) << endl;
        }

        else if(str.substr(0, 5) == "type ")
        {
            handleType(str.substr(5));
        }
        else if(str == "pwd"){
            handlePwd();

        }

        else
        {
            executeExternalCommand(str);
        }
    }

    return 0;
}
