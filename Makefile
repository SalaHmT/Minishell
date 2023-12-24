# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 21:34:54 by shamsate          #+#    #+#              #
#    Updated: 2023/12/24 23:44:02 by shamsate         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minishell

CFLAGS  =   -Wall -Wextra -Werror

LIB =  -L ~/.brew/opt/readline/lib
INC =  -I ~/.brew/opt/readline/include

CC      = cc

RM      = rm -rf

READLINE = -lreadline

HEADER  = include/minishell.h

YELLOW	=	$(shell tput -Txterm setaf 4)
GREEN	=	$(shell tput -Txterm setaf 5)

C_BLUE  = \033[1;34m
C_CYAN  = \033[1;36m
C_RESET = \033[34m

O_DIR   := OBJ_DER

UTIL = $(addprefix utils_libft/, free_tab.c ft_bzero.c ft_strlen.c ft_strcmp.c ft_joinstr.c ft_strdup.c \
	ft_split.c ft_putstr_fd.c ft_putchar_fd.c ft_itoa.c ft_strchr.c ft_realloc.c ft_memmove.c \
	ft_memcpy.c ft_calloc.c ft_strncmp.c ft_joinchar.c ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_memset.c)

PARS = $(addprefix src/parsing/, dependencies/check_utils_synx.c dependencies/cmd_add_clear.c dependencies/get_command.c \
	dependencies/in_out_file.c dependencies/lst_add_clear.c dependencies/tkn_data_check.c dependencies/tkn_data_check_part2.c \
	dependencies/tokenizer_and_start.c lexer/add_cmd_token.c lexer/check_cmd_data.c expand/expand_utils.c expand/name_expand.c\
	expand/expand.c heredoc/heredoc_utils.c heredoc/heredoc.c)

EXEC = $(addprefix src/execution/, )

M_SRCS = main.c $(UTIL) $(EXEC) $(PARS)

M_OBJS = $(patsubst %.c,$(O_DIR)/%.o,$(M_SRCS))

all: $(NAME)

$(NAME): $(M_OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(M_OBJS) $(READLINE) $(LIB) -o $(NAME)
	@echo "\n 			-  Execution ready..✔️\n"

$(O_DIR)/%.o: %.c $(HEADER)
	@echo "- Making Object file $(notdir $@) from source file $(notdir $<)...\n"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@$(RM) $(O_DIR)
	@echo "\n- Object file Removed. ✔️\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "- Removing $(NAME) ..\n"
	@echo "- Removed. ✔️\n"

re: fclean all

.PHONY: all clean fclean re