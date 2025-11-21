SRC = 	main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = HumanAttac

COMPILER = c++
FLAGS = -Wall -Wextra -Werror -g
PLUSFLAG = -std=c++98
HEADERS = HumanA.hpp HumanB.hpp Weapon.hpp 

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) $(PLUSFLAG) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(COMPILER) $(FLAGS) $(PLUSFLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all clean
