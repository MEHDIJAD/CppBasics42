# Project Overview

This project is a series of C++ exercises, each contained in its own directory (e.g., `ex00`, `ex01`, etc.). Each exercise is a small, self-contained program that demonstrates a specific C++ concept.

# Building and Running

Each exercise can be built and run independently. To build and run an exercise, navigate to its directory and use the `make` command.

**Example:**

```bash
cd ex00
make
./Zombie
```

The `Makefile` in each directory provides the following targets:

*   `all`: Builds the executable.
*   `clean`: Removes the object files.
*   `fclean`: Removes the object files and the executable.
*   `re`: Rebuilds the project from scratch.

# Development Conventions

*   The code is written in C++98.
*   The code is compiled with the `c++` compiler.
*   The code is compiled with the `-Wall`, `-Wextra`, and `-Werror` flags.
*   Each exercise has its own `Makefile`.
*   The code is organized into `.cpp` and `.hpp` files.
*   **AI Instruction:** Do not execute any files or commands until explicitly instructed by the user.