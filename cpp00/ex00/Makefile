# Defines variable. Stores string "megaphone.cpp". Can be referenced as $(SRC).
SRC = megaphone.cpp

# Pattern substitution. Takes value of SRC, replaces ".cpp" with ".o". Result: "megaphone.o"
OBJ = $(SRC:.cpp=.o)

# Defines variable. The executable's name.
NAME = megaphone

# Configuration variables. Store compiler path and compilation flags.
Compiler = c++
FLAGS = -Wall -Wextra -Werror
PLUSFLAG = -std=c++98

# Target declaration. When you type make, it builds this (default first target). 
# Depends on $(NAME), so Make will build that first.
all: $(NAME)

$(NAME): $(OBJ)
	$(Compiler) $(FLAGS) $(PlusFLAG) $(OBJ) -o $(NAME)

# c++ -Wall -Wextra -Werror -std=c++98 megaphone.o -o megaphone

%.o: %.cpp
	$(Compiler) $(FLAGS) $(PlusFLAG) -c $< -o $@

# c++ -Wall -Wextra -Werror -std=c++98 -c megaphone.cpp -o megaphone.o

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
