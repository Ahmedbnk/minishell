NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iinclude
SRCS = main.c \
	src/env/copy_env.c \
	src/env/allocate_and_init_expand_list.c \
	src/expansion/expand_if_possible.c \
	src/utils/custom_join.c \
	src/expansion/should_i_expand.c \
	src/expansion/is_expand_separator.c \
	src/expansion/new_string_after_expand.c \
	src/parser/check_input_error.c \
	src/parser/remove_quotes_from_args.c \
	src/parser/split_with_operators.c \
	src/parser/make_token.c \
	src/parser/is_between_quotes.c \
	src/parser/customized_split.c \
	src/utils/is_space.c \
	src/utils/are_they_equal.c \
	src/utils/len_of_two_d_array.c \
	src/utils/print_splitted.c \
	src/utils/ft_strchr.c \
	src/utils/get_next_line.c \
	src/signals/handle_signals.c\
	src/utils/ft_isalnum.c\
	src/utils/ft_memcpy.c\
	src/utils/ft_split.c\
	src/utils/ft_strdup.c\
	src/utils/ft_itoa.c\
	src/utils/ft_strjoin.c\
	src/utils/ft_strlen.c\
	src/utils/ft_substr.c\
	src/utils/garbage_collection_lstnew.c\
	src/utils/garbage_collector.c\
	src/utils/ft_lstnew.c\
	src/utils/ft_lstadd_back.c\
	src/parser/execute_command_line.c\
	src/parser/handle_heredoc.c\
	src/parser/get_files_name.c\
	src/utils/print_file.c\
	src/parser/handle_redir_in.c\
	src/utils/read_file.c\
	src/utils/print_error.c\
	src/parser/handle_redir_out.c\
	src/parser/handle_append.c \
	src/execution/execute_command.c\
	src/built_in/ft_strncmp.c\
	src/built_in/ft_isalpha.c\
	src/built_in/ft_isdigit.c\
	src/built_in/ft_strcmp.c\
	src/parser/handle_dollar_with_quotes.c\
	src/execution/print_exit_signal_message.c\
	src/expansion/ft_get_env_var.c\
	src/expansion/expand_outside_dollars.c\
	src/utils/generate_random_name.c\
	src/utils/is_quote.c\
	src/utils/is_protected.c\
	src/utils/is_all_spaces.c\
	src/utils/ft_lstsize.c\
	src/utils/it_there_a_pipe.c\
	src/utils/is_dollar.c\
	src/utils/is_redirection.c\
	src/utils/lst_file_name_func.c\
	src/tools/printf_for_deb.c\
	src/utils/is_pipe.c\
	src/core/is_it_valid_dollar.c \
	src/core/is_there_invalid_expantion.c \
	src/core/split_after_expantion.c \
	src/core/expand_and_split_helper.c \
	src/core/expand_and_split.c \
	src/core/parse_line.c \
	src/core/execute_line.c \
	src/core/ft_readline.c \
	src/core/ft_init_shell_block.c \
	src/utils/get_shell_pointer.c\
	src/built_in/is_builtin_function.c \
	src/built_in/add_var_to_env.c \
	src/built_in/advance_file_name_list.c \
	src/built_in/check_ambiguous_redirection.c \
	src/built_in/compare_env_var.c \
	src/built_in/cd_function.c \
	src/built_in/echo_function.c \
	src/built_in/execute_builtin.c \
	src/built_in/execute_parent_builtin.c \
	src/built_in/export_function.c \
	src/built_in/find_and_update_var.c \
	src/built_in/init_redirection_vars.c \
	src/built_in/is_it_key_value.c \
	src/built_in/is_the_var_in_env.c \
	src/built_in/is_valid_flag.c \
	src/built_in/is_valid_var.c \
	src/built_in/parse_redirections.c \
	src/built_in/print_env.c \
	src/built_in/process_redirection_tokens.c \
	src/built_in/pwd_function.c \
	src/built_in/remove_var_from_env.c \
	src/built_in/restore_original_fds.c \
	src/built_in/save_original_fds.c \
	src/built_in/setup_input_redirection.c \
	src/built_in/setup_output_redirection.c \
	src/built_in/sort_env.c \
	src/built_in/unset_function.c \
	src/built_in/update_env_dir.c \


OBJS = $(SRCS:.c=.o)

READLINE =-lreadline

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(READLINE) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re
