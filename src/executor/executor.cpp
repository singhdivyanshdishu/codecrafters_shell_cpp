#include "executor.hpp"

#include "../path/path.hpp"

#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

using namespace std;

void executeExternalCommand(const ParsedCommand& cmd)
{
    const vector<string>& tokens = cmd.args;

    if(tokens.empty())
    {
        return;
    }

    string path = findExecutable(tokens[0]);

    if(path.empty())
    {
        cout << tokens[0] << ": command not found" << endl;
        return;
    }

    vector<char*> argv;

    for(const auto& token : tokens)
    {
        argv.push_back(const_cast<char*>(token.c_str()));
    }

    argv.push_back(nullptr);

    pid_t pid = fork();

    if(pid == 0)
    {
        if(cmd.redirectStdout)
        {
            int fd = open(
                cmd.outputFile.c_str(),
                O_WRONLY | O_CREAT | O_TRUNC,
                0644
            );

            dup2(fd, STDOUT_FILENO);
            close(fd);
        }

        execv(path.c_str(), argv.data());

        exit(1);
    }
    else
    {
        waitpid(pid, nullptr, 0);
    }
}
