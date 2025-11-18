SRC = tests.cpp Account.cpp

OBJ = $(SRC:.cpp=.o)

NAME = Bank

COMPILER = c++
FLAGS = -Wall -Wextra -Werror
PLUSFLAG = -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) $(PLUSFLAG) $(OBJ) -o $(NAME)

%.o: %.cpp Account.hpp
	$(COMPILER) $(FLAGS) $(PLUSFLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all clean

