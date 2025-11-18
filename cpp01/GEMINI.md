# C++ Project: Zombie

## Project Overview

This directory contains a C++ exercise that involves implementing a `Zombie` class. The goal is to create a `Zombie` class and functions to create and manage zombie objects.

## Building and Running

The `Makefile` in the `ex00` directory is currently empty. To build and run this project, you will need to write a `Makefile` that compiles the C++ source files (`.cpp`) into an executable.

A typical `Makefile` for this project might look like this:

```makefile
NAME = zombie
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
```

Once you have a `Makefile`, you can build the project by running `make` in the `ex00` directory.

## Development Conventions

The header file `Zombie.hpp` defines the `Zombie` class. You will need to implement the methods of this class in `Zombie.cpp`. The other `.cpp` files (`newZombie.cpp`, `randomChump.cpp`, and `main.cpp`) likely contain other functions that you need to implement.
