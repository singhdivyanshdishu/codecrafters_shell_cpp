# Mini Shell (C++)

A POSIX-inspired shell built in C++ as part of the CodeCrafters **"Build Your Own Shell"** challenge.

It recreates core shell functionality such as command parsing, built-in commands, process execution, PATH resolution, quoting, redirection, and progressively expands toward command completion, pipelines, job control, history, parameter expansion, and other shell features.

## Challenge Progress

- [x] Introduction
- [x] Navigation
- [x] Quoting
- [x] Redirection
- [ ] Command Completion
    - [ ] Builtin completion
    - [ ] Completion with arguments
    - [ ] Missing completions
    - [ ] Executable completion
    - [ ] Multiple completions
    - [ ] Partial completions
- [ ] Filename Completion
- [ ] Programmable Completion
- [ ] Background Jobs
- [ ] Pipelines
- [ ] History
- [ ] History Persistence
- [ ] Parameter Expansion

## Features Implemented

### Shell Core

- Interactive REPL
- Built-in command dispatch
- External command execution
- Executable lookup using `PATH`

### Built-in Commands

- `echo`
- `exit`
- `type`
- `pwd`
- `cd`

### Parsing

- Command tokenization
- Single quote handling
- Double quote handling
- Backslash escaping
- Quoted executable execution

### Redirection

- `>` Redirect stdout
- `>>` Append stdout
- `2>` Redirect stderr
- `2>>` Append stderr

## Example

```bash
$ pwd
/home/divyansh

$ type ls
ls is /usr/bin/ls

$ echo Hello World > output.txt

$ cat output.txt
Hello World

$ ls nonexistent 2>> errors.txt

$ cat errors.txt
ls: cannot access 'nonexistent': No such file or directory
```

## Requirements

### Arch Linux

```bash
sudo pacman -S --needed base-devel cmake git
```

### Ubuntu / Debian

```bash
sudo apt update
sudo apt install build-essential cmake git
```

## Clone Repository

```bash
git clone https://github.com/singhdivyanshdishu/codecrafters_shell_cpp.git
cd codecrafters_shell_cpp
```

## Build

```bash
cmake -B build
cmake --build build
```

## Run

Using the CodeCrafters wrapper:

```bash
./your_program.sh
```

Or directly:

```bash
./build/shell
```

## Learning Objectives

Through this project I aim to gain a deeper understanding of:

- POSIX shells
- Process creation and management (`fork`, `execv`, `waitpid`)
- Command parsing and lexical analysis
- PATH resolution
- Built-in command implementation
- File descriptors
- Input/output redirection
- Pipelines
- Terminal interaction
- Systems programming in C++

## Concepts Covered

- POSIX APIs
- Linux Systems Programming
- Process Management
- Shell Parsing
- Lexical Analysis
- Command Execution
- PATH Resolution
- File Descriptors
- Input/Output Redirection
- Modern C++
- CMake

## Project Architecture

```text
codecrafters-shell-cpp/
│
├── src/
│   │
│   ├── main.cpp
│   │
│   ├── parser/
│   │   ├── tokenizer.cpp
│   │   ├── tokenizer.hpp
│   │   ├── parser.cpp
│   │   └── parser.hpp
│   │
│   ├── models/
│   │   └── parsed_command.hpp
│   │
│   ├── builtins/
│   │   ├── echo.cpp
│   │   ├── pwd.cpp
│   │   ├── cd.cpp
│   │   ├── type.cpp
│   │   ├── history.cpp
│   │   ├── jobs.cpp
│   │   └── builtins.hpp
│   │
│   ├── executor/
│   │   ├── executor.cpp
│   │   ├── redirection.cpp
│   │   ├── pipeline.cpp
│   │   ├── background.cpp
│   │   └── executor.hpp
│   │
│   ├── completion/
│   │   ├── builtin_completion.cpp
│   │   ├── executable_completion.cpp
│   │   ├── file_completion.cpp
│   │   ├── programmable_completion.cpp
│   │   └── completion.hpp
│   │
│   ├── history/
│   │   ├── history_manager.cpp
│   │   └── history_manager.hpp
│   │
│   ├── input/
│   │   ├── line_editor.cpp
│   │   └── line_editor.hpp
│   │
│   ├── jobs/
│   │   ├── job_manager.cpp
│   │   └── job_manager.hpp
│   │
│   ├── variables/
│   │   ├── variables.cpp
│   │   ├── expansion.cpp
│   │   └── variables.hpp
│   │
│   ├── path/
│   │   ├── path.cpp
│   │   └── path.hpp
│   │
│   └── utils/
│       ├── string_utils.cpp
│       └── string_utils.hpp
│
├── tests/
├── CMakeLists.txt
├── your_program.sh
└── README.md
```

### Module Responsibilities

| Module | Responsibility |
|----------|---------------|
| `parser` | Tokenization, quoting rules, and command parsing |
| `models` | Shared shell data structures |
| `builtins` | Built-in commands such as `echo`, `cd`, `pwd`, `type`, `history`, and `jobs` |
| `executor` | Process execution, redirection, pipelines, and background jobs |
| `completion` | Command, executable, filename, and programmable completion |
| `history` | Command history and history persistence |
| `jobs` | Background job tracking and job management |
| `variables` | Shell variables and parameter expansion |
| `path` | PATH resolution and executable discovery |
| `utils` | Shared helper functions and utilities |

## Tech Stack

- C++17
- CMake
- POSIX APIs
- Linux
- CodeCrafters

## Platform Support

- ✅ Linux
- ✅ WSL (Windows Subsystem for Linux)
- ⚠️ Native Windows not tested

This project uses POSIX APIs and is primarily developed and tested on Linux-based environments.

## Motivation

This project is a hands-on exploration of Unix shell internals and systems programming. Rather than studying operating system concepts in isolation, each Codecrafters stage incrementally builds a functional shell while reinforcing process management, command parsing, file descriptors, POSIX APIs, and modern C++ software design.

The repository will continue to evolve as additional shell features are implemented throughout the CodeCrafters challenge.

 ##Mini Shell Architecture


