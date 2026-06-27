# Mini Shell (C++)

A POSIX-inspired shell built in C++ as part of the CodeCrafters **"Build Your Own Shell"** challenge.

This project explores how real shells work internally by implementing command parsing, built-in commands, process execution, PATH resolution, quoting, redirection, pipelines, and other core shell features from scratch.

## Challenge Progress

- [x] Introduction
- [x] Navigation
- [x] Quoting
- [ ] Redirection
    - [x] Redirect stdout
    - [x] Redirect stderr
    - [x] Append stdout
    - [ ] Append stderr
- [ ] Command Completion
- [ ] Filename Completion
- [ ] Programmable Completion
- [ ] Background Jobs
- [ ] Pipelines
- [ ] History
- [ ] History Persistence
- [ ] Parameter Expansion

## Features Implemented

- Interactive REPL
- `echo` builtin
- `type` builtin
- `pwd` builtin
- `cd` builtin
- Executable lookup using `PATH`
- External command execution
- Command tokenization
- Single quote handling
- Double quote handling
- Escape sequence handling

## Example

```bash
$ pwd
/home/divyansh

$ echo hello world
hello world

$ type ls
ls is /usr/bin/ls

$ cd /tmp

$ pwd
/tmp
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

- Shell internals
- Process creation and management
- Command parsing
- PATH resolution
- Built-in command implementation
- File descriptors
- Input/output redirection
- Pipelines
- POSIX system calls
- Systems programming in C++

## Planned Architecture

The current implementation is intentionally kept in a single source file (`src/main.cpp`) while progressing through the CodeCrafters Shell challenge.

As more advanced features are added (redirection, pipelines, job control, history, completion, parameter expansion, etc.), the project will be refactored into a modular architecture similar to real-world shell implementations.

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
| `parser` | Tokenization, quoting rules, command parsing |
| `models` | Shared shell data structures |
| `builtins` | Built-in commands such as `echo`, `cd`, `pwd`, `type`, `history`, and `jobs` |
| `executor` | Process execution, redirection, pipelines, and background jobs |
| `completion` | Command, executable, filename, and programmable completion |
| `history` | Command history and history persistence |
| `jobs` | Background job tracking and job management |
| `variables` | Shell variables and parameter expansion |
| `path` | PATH resolution and executable discovery |
| `utils` | Shared helper functions and utilities |

### Refactoring Roadmap

- [ ] Extract `ParsedCommand` into a dedicated model
- [ ] Extract tokenizer and parser into separate modules
- [ ] Extract built-in commands into a dedicated subsystem
- [ ] Extract process execution and redirection logic
- [ ] Introduce a multi-file CMake build structure
- [ ] Add unit tests
- [ ] Complete full modular shell architecture

## Tech Stack

- C++17
- CMake
- POSIX APIs
- CodeCrafters

## Platform Support

- ✅ Linux
- ✅ WSL (Windows Subsystem for Linux)
- ⚠️ Native Windows not tested

This project uses POSIX APIs and is primarily developed and tested on Linux environments.

## Motivation

I am building this project to strengthen my systems programming skills and gain hands-on experience with how command-line interpreters work under the hood.

This repository will continue to evolve as I progress through the CodeCrafters Shell challenge.
