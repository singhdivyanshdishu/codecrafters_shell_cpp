# Mini Shell (C++)

A POSIX-inspired shell built in C++ as part of the CodeCrafters **"Build Your Own Shell"** challenge.

This project is focused on understanding how real shells work internally by implementing command parsing, built-in commands, process execution, PATH resolution, redirection, pipelines, and other core shell features from scratch.

## Challenge Progress
![CodeCrafters](https://backend.codecrafters.io/progress/shell/ba7bd936-33d7-46a1-83c8-05ab10dde777)

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

## Project Structure

```text
.
├── src/
│   └── main.cpp
├── CMakeLists.txt
├── codecrafters.yml
├── vcpkg.json
└── README.md
```

## Build

```bash
cmake -B build
cmake --build build
```

## Run

```bash
./your_program.sh
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

## Progress

Current CodeCrafters Progress:

- [x] REPL
- [x] echo
- [x] type
- [x] pwd
- [x] cd
- [x] External commands
- [x] Tokenization
- [ ] Redirection
- [ ] Pipelines
- [ ] Advanced shell features

## Tech Stack

- C++17
- CMake
- POSIX APIs
- CodeCrafters

## Motivation

I am building this project to strengthen my systems programming skills and gain hands-on experience with how command-line interpreters work under the hood.

This repository will continue to evolve as I progress through the CodeCrafters Shell challenge.
