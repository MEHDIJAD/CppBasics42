SRC = 	main.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = findRep

COMPILER = c++
FLAGS = -Wall -Wextra -Werror -g
PLUSFLAG = -std=c++98
HEADERS = 

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
