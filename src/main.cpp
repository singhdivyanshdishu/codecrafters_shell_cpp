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
vector<string> tokenize(const string& line);

bool isBuiltin(const string& cmd)
{
    return cmd == "echo" ||
           cmd == "exit" ||
           cmd == "type" ||
           cmd == "pwd"  ||
           cmd == "cd"   ;
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
     vector<string> tokens = tokenize(line);
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

void handleCd(string pathStr)
{
    if(pathStr == "~"){
        pathStr = getenv("HOME");
    }
    fs::path p = pathStr;

    if (!fs::exists(p))
    {
        cout << "cd: " << pathStr << ": No such file or directory" << endl;
        return;
    }

    if (!fs::is_directory(p))
    {
        cout << "cd: " << pathStr << ": No such file or directory" << endl;
        return;
    }

    fs::current_path(p);
}

vector<string> tokenize(const string& line)
{
    vector<string> tokens;
    string current;

    bool inSingleQuotes = false;
    bool inDoubleQuotes = false;
    bool escape = false;

    for(char ch : line)
    {
        if(escape){
            current+= ch;
            escape = false ;
            continue;
        }
        // Toggle single quotes only when not inside double quotes
        if(ch == '\'' && !inDoubleQuotes)
        {
            inSingleQuotes = !inSingleQuotes;
        }

        // Toggle double quotes only when not inside single quotes
        else if(ch == '"' && !inSingleQuotes)
        {
            inDoubleQuotes = !inDoubleQuotes;
        }

        // Space splits arguments only outside ALL quotes
        else if(ch == ' ' && !inSingleQuotes && !inDoubleQuotes)
        {
            if(!current.empty())
            {
                tokens.push_back(current);
                current.clear();
            }
        }

        // Normal character
        else
        {
            current += ch;
        }
    }

    if(!current.empty())
    {
        tokens.push_back(current);
    }

    return tokens;
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
    // Use tokenizer so quoted arguments are parsed correctly.
    vector<string> tokens = tokenize(str);

    for(size_t i = 1; i < tokens.size(); i++)
    {
        if(i > 1)
        {
            cout << " ";
        }

        cout << tokens[i];
    }

    cout << endl;
}

        else if(str.substr(0, 5) == "type ")
        {
            handleType(str.substr(5));
        }
        else if(str == "pwd"){
            handlePwd();
        }
        else if(str.substr(0,2)=="cd"){
            handleCd(str.substr(3));
        }
        else
        {
            executeExternalCommand(str);
        }
    }
    return 0;
}
