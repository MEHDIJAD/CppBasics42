SRC =  main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = Refrance

COMPILER = c++
FLAGS = -Wall -Wextra -Werror -g
PLUSFLAG = -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) $(PLUSFLAG) $(OBJ) -o $(NAME)

%.o: %.cpp  Zombie.hpp
	$(COMPILER) $(FLAGS) $(PLUSFLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all clean
