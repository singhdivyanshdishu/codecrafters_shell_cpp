#include <iostream>
#include <string>
#include <sstream>
#include <filesystem>
#include <cstdlib>

using namespace std;
namespace fs = std::filesystem;

int main() {
    cout << unitbuf;
    cerr << unitbuf;

    while (true) {
        cout << "$ ";

        string str;
        getline(cin, str);

        if (str == "exit") {
            break;
        }

        else if (str.substr(0, 5) == "echo ") {
            cout << str.substr(5) << endl;
        }

        else if (str.substr(0, 5) == "type ") {
            string cmd = str.substr(5);

            if (cmd == "echo" || cmd == "exit" || cmd == "type") {
                cout << cmd << " is a shell builtin" << endl;
            }
            else {
                char* pathEnv = getenv("PATH");

                bool found = false;

                if (pathEnv != nullptr) {
                    string path(pathEnv);
                    string dir;

                    stringstream ss(path);

                    while (getline(ss, dir, ':')) {
                        fs::path candidate = fs::path(dir) / cmd;

                        if (fs::exists(candidate)) {
                            cout << cmd << " is " << candidate.string() << endl;
                            found = true;
                            break;
                        }
                    }
                }

                if (!found) {
                    cout << cmd << ": not found" << endl;
                }
            }
        }

        else {
            cout << str << ": command not found" << endl;
        }
    }

    return 0;
}
