NAME = philosopher
CC = cc
C_FLAGS = -Wall -Wextra -Werror

SRC_UTILS = ft_atoi.c ft_putstr_fd.c get_current_time.c parsing.c \
			philos_init.c put_error.c table_init.c

SRC_ROUTINE = 

SRC = philosopher.c \
	  $(addprefix Utils/, $(SRC_UTILS)) \
	  $(addprefix Routine/, $(SRC_ROUTINE)) \
	  
OBJ = $(SRC:.c=.o)

DEPENDENCIES = $(OBJ:.o=.d)

INCLUDES = -I Includes

all: $(NAME)

-include $(DEPENDENCIES)

$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(C_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEPENDENCIES)

fclean: clean
	rm -f $(NAME)

re: fclean all

redo: re
	make clean
	clear

.PHONY: all clean fclean re redo

