#include "builtins.hpp"

#include <filesystem>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

void handlePwd()
{
    cout << fs::current_path().string() << endl;
}
