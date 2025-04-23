NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c check_input_error.c handle_signals.c is_between_quotes.c \
	is_space.c customized_split.c remove_quotes.c are_they_equal.c make_token.c \

OBJS = $(SRCS:.c=.o)

LIBFT = Libft/libft.a
READLINE = -lreadline

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C Libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean:
	$(MAKE) -C Libft clean
	rm -f $(OBJS) 

fclean: clean
	$(MAKE) -C Libft fclean
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re
