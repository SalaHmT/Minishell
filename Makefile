NAME = Minishell

YELLOW	=	$(shell tput -Txterm setaf 3)
GREEN	=	$(shell tput -Txterm setaf 2)

C_BLUE  = \033[0;34m
C_CYAN  = \033[0;36m
C_RESET = \033[0m

CC      = cc

RM      = rm -rf

CFLAGS  = -Wall -Wextra -Werror 

HEADER  = minishell.h

O_DIR   := OBJ_DER

M_SRCS = minishell.c

M_OBJS = $(patsubst %.c,$(O_DIR)/%.o,$(M_SRCS))

all: $(NAME)

Prj_Name = "\n" \
	"$(YELLOW)███$(GREEN)╗   $(YELLOW)███$(GREEN)╗ $(YELLOW)██$(GREEN)╗ $(YELLOW)███$(GREEN)╗  $(YELLOW)\
	██$(GREEN)╗ $(YELLOW)██$(GREEN)╗ $(YELLOW)███████$(GREEN)╗ $(YELLOW)██$(GREEN)╗  $(YELLOW)██$(GREEN)╗ \
	$(YELLOW)███████$(GREEN)╗ $(YELLOW)██$(GREEN)║      $(YELLOW)██$(GREEN)║     \n" \
	"$(YELLOW)████$(GREEN)╗ $(YELLOW)████$(GREEN)║ $(YELLOW)██$(GREEN)║ $(YELLOW)████$(GREEN)╗  $(YELLOW)██$(GREEN)║\
	 $(YELLOW)██$(GREEN)║ $(YELLOW)██$(GREEN)╔════╝ $(YELLOW)██$(GREEN)║  $(YELLOW)██$(GREEN)║\
	  $(YELLOW)██$(GREEN)╔════╝ $(YELLOW)██$(GREEN)║      $(YELLOW)██$(GREEN)║     \n" \
	"$(YELLOW)██$(GREEN)╔$(YELLOW)████$(GREEN)╔$(YELLOW)██$(GREEN)║ $(YELLOW)██$(GREEN)║ \
	$(YELLOW)██$(GREEN)╔$(YELLOW)██$(GREEN)╗ $(YELLOW)██$(GREEN)║ $(YELLOW)██$(GREEN)║\
	 $(YELLOW)███████$(GREEN)╗ $(YELLOW)███████$(GREEN)║ \
	 $(YELLOW)█████$(GREEN)╗   $(YELLOW)██$(GREEN)║      $(YELLOW)██$(GREEN)║     \n" \
	"$(YELLOW)██$(GREEN)║╚$(YELLOW)██$(GREEN)╔╝$(YELLOW)██$(GREEN)║ $(YELLOW)██$(GREEN)║\
	 $(YELLOW)██$(GREEN)║╚$(YELLOW)██$(GREEN)╗$(YELLOW)██$(GREEN)║ $(YELLOW)██$(GREEN)║ \
	 ╚════$(YELLOW)██$(GREEN)║ $(YELLOW)██$(GREEN)╔══$(YELLOW)██$(GREEN)║ \
	 $(YELLOW)██$(GREEN)╔══╝   $(YELLOW)██$(GREEN)║      $(YELLOW)██$(GREEN)║     \n" \
	"$(YELLOW)██$(GREEN)║ $(GREEN)╚═╝ $(YELLOW)██$(GREEN)║ $(YELLOW)██$(GREEN)║ $(YELLOW)██$(GREEN)║ \
	$(GREEN)╚$(YELLOW)████$(GREEN)║ $(YELLOW)██$(GREEN)║ $(YELLOW)███████$(GREEN)║ \
	$(YELLOW)██$(GREEN)║  $(YELLOW)██$(GREEN)║ $(YELLOW)███████$(GREEN)╗ $(YELLOW)███████$(GREEN)╗ $(YELLOW)███████$(GREEN)╗\n" \
	"$(GREEN)╚═╝     $(GREEN)╚═╝ $(GREEN)╚═╝ $(GREEN)╚═╝  $(GREEN)╚═══╝ $(GREEN)╚═╝\
	 $(GREEN)╚══════╝ $(GREEN)╚═╝  $(GREEN)╚═╝ $(GREEN)╚══════╝ $(GREEN)╚══════╝\
	  $(GREEN)╚══════╝\n$(C_RESET)" \


$(NAME): $(M_OBJS) $(HEADER)
	@echo $(Prj_Name)
	@$(CC) $(CFLAGS) $(M_OBJS) -o $(NAME)
	@echo "$(C_BLUE)		✅ Compilation completed successfully!$(C_RESET)"

$(O_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(O_DIR)
	@echo "$(C_CYAN)🗑️  Object Directory has been removed......$(C_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(C_CYAN)	🚀 'Minishell' executable has been removed.....$(C_RESET)"

re: fclean all

.PHONY: all clean fclean re