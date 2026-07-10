NAME = philosopher
CC = cc
C_FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_UTILS = 

SRC_ROUTINE = 

SRC = philosopher.c \
	  $(addprefix Utils/, $(SRC_UTILS)) \
	  $(addprefix Routine/, $(SRC_ROUTINE)) \
	  
OBJ = $(SRC:.c=.o)

DEPENDENCIES = $(OBJ:.o=.d)

INCLUDES = -I Includes -I $(LIBFT_DIR)

all: $(LIBFT) $(NAME)

-include $(DEPENDENCIES)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(C_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEPENDENCIES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

redo: re
	make clean
	clear

.PHONY: all clean fclean re redo

