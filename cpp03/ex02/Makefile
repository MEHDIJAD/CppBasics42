# Source files are now in the src directory
SRC_DIR = src
# List of source file names (excluding main.cpp)
SRC_FILES = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
# Full paths to source files in SRC_DIR
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Directory where header (.hpp) files are located
INCL_DIR = incl
# List of all header file names
HEADER_FILES = ClapTrap.hpp FragTrap.hpp ScavTrap.hpp
# Full paths to header files
HEADER = $(addprefix $(INCL_DIR)/, $(HEADER_FILES))

# main.cpp is in the root directory
MAIN_SRC = main.cpp
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)

# Directory where other object (.o) files will be stored
OBJ_DIR = obj
# Object files from SRC_DIR, prefixed with OBJ_DIR
OTHER_OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

# All object files (main.o in root, others in obj/)
OBJ = $(MAIN_OBJ) $(OTHER_OBJ)

# Name of the final executable
NAME = program

# C++ Compiler to use
COMPILER = c++
# Compiler flags:
# -Wall: Enable all standard warnings
# -Wextra: Enable extra warnings
# -Werror: Treat warnings as errors
# -g: Include debugging information
# -Iincl: Add the 'incl' directory to the include search path for headers
FLAGS = -Wall -Wextra -Werror -g -I$(INCL_DIR)
# C++ standard flag
PLUSFLAG = -std=c++98

# --- Targets ---

# Default target: builds the program
# Depends on the object directory existing and the program executable
all: $(OBJ_DIR) $(NAME)

# Target to link object files into the final executable
# Depends on all object files being built
$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) $(PLUSFLAG) $(OBJ) -o $(NAME)

# Target to create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to compile main.cpp (in root) into main.o (in root)
$(MAIN_OBJ): $(MAIN_SRC) $(HEADER)
	$(COMPILER) $(FLAGS) $(PLUSFLAG) -c $< -o $@

# Rule to compile other source files (in src/) into object files (in obj/)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER)
	$(COMPILER) $(FLAGS) $(PLUSFLAG) -c $< -o $@

# Target to clean up generated object files
clean:
	@rm -f $(OBJ)

# Target to clean up all generated files (object files and executable)
fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR) # Also remove the object directory

# Target to re-build the entire project (clean, then build all)
re: fclean all

# Target to build and then run the program
run: all
	./$(NAME)

# Phony targets are not actual files; they are just names for commands
.PHONY: all clean fclean re run
