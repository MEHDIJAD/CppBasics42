SRC_DIR = src
SRC_FILES = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

MAIN_SRC = main.cpp
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)

OBJ_DIR = obj
OTHER_OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

OBJ = $(MAIN_OBJ) $(OTHER_OBJ)

NAME = DiamondTrap

COMPILER = c++
FLAGS = -Wall -Wextra -Werror  -Wshadow -g -Iincl
PLUSFLAG = -std=c++98


all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) $(PLUSFLAG) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(MAIN_OBJ): $(MAIN_SRC)
	$(COMPILER) $(FLAGS) $(PLUSFLAG) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(COMPILER) $(FLAGS) $(PLUSFLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR) # Also remove the object directory


re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run
