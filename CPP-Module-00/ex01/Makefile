SRC = main.cpp Contact.cpp PhoneBook.cpp

OBJ = $(SRC:.cpp=.o)

NAME = PhoneBook

COMPILER = c++
FLAGS = -Wall -Wextra -Werror
PLUSFLAG = -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) $(PLUSFLAG) $(OBJ) -o $(NAME)

%.o: %.cpp  Contact.hpp PhoneBook.hpp
	$(COMPILER) $(FLAGS) $(PLUSFLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all clean
