NAME = minishell

CC = cc -g

FLAGS = -Wall -Wextra -Werror
SRC = main.c

OPJ = $(SRC:.c=.o)

RDLINE = -lreadline

all: $(NAME)

$(NAME): $(OPJ)
	$(CC) $(FLAGS) $(OPJ) $(RDLINE) -o $(NAME)

.o:.c
	$(SRC) $(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OPJ)

fclean:
	rm -f $(OPJ) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
