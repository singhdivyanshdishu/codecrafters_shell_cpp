# Mini Shell (C++)

A POSIX-inspired shell built in C++ as part of the CodeCrafters **"Build Your Own Shell"** challenge.

This project explores how real shells work internally by implementing command parsing, built-in commands, process execution, PATH resolution, quoting, redirection, pipelines, and other core shell features from scratch.

## Challenge Progress

- [x] Introduction
- [x] Navigation
- [ ] Quoting
  - [x] Single quotes
  - [x] Double quotes
  - [x] Backslash outside quotes
  - [x] Backslash within single quotes
  - [x] Backslash within double quotes
  - [ ] Executing a quoted executable
- [ ] Redirection
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

## Tech Stack

- C++17
- CMake
- POSIX APIs
- CodeCrafters

## Platform Support

- ✅ Linux
- ⚠️ Windows (untested)
- ⚠️ macOS (untested)

This project uses POSIX APIs and is primarily developed and tested on Linux.

## Motivation

I am building this project to strengthen my systems programming skills and gain hands-on experience with how command-line interpreters work under the hood.

This repository will continue to evolve as I progress through the CodeCrafters Shell challenge.
