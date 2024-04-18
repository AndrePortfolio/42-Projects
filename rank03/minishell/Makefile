NAME = minishell
LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
READLINELIB = -lreadline
CFLAGS = -Wall -Wextra -Werror -g
CC = cc
COMPRESS = ar rcs
RM = rm -rf

OBJ_DIR = objects
SRC_DIRS = sources/1.parsing sources/2.tokenization sources/3.builtins sources/4.execution sources/5.signals sources sources/main_utils

SRC_1_parsing = check_syntax.c expander_utils.c expander.c parse_cmd_line.c parsing_utils.c
SRC_2_tokenization = check_tokens.c tokenization_utils.c tokenization_utils2.c tokenization.c tokenize.c
SRC_3_builtins = builtins.c mini_cd_utils.c mini_cd.c mini_echo.c mini_env.c mini_exit.c mini_export_utils.c mini_export_utils2.c \
				mini_export.c mini_pwd.c mini_unset.c mini_utils.c
SRC_4_execution = execution_utils.c  execution_utils2.c execution.c get_path.c here_doc.c open_files.c
SRC_5_signals = signals.c
SRC_main_utils = close_program.c free_all.c init_shell.c loop.c printing_tests.c utils.c
SRC_main = minishell.c

SRC =
SRC += $(addprefix sources/1.parsing/,$(SRC_1_parsing))
SRC += $(addprefix sources/2.tokenization/,$(SRC_2_tokenization))
SRC += $(addprefix sources/3.builtins/,$(SRC_3_builtins))
SRC += $(addprefix sources/4.execution/,$(SRC_4_execution))
SRC += $(addprefix sources/5.signals/,$(SRC_5_signals))
SRC += $(addprefix sources/main_utils/,$(SRC_main_utils))
SRC += $(addprefix sources/,$(SRC_main))

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Colours
GREEN = \033[1;32m
ORANGE = \033[1;33m
RED = \033[1;31m
CYAN = \033[1;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(READLINELIB)
	@echo "$(CYAN)make$(RESET)   $@ $(GREEN)[OK]$(RESET)"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: sources/1.parsing/%.c sources/2.tokenization/%.c sources/3.builtins/%.c sources/4.execution/%.c sources/5.signals/%.c sources/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(ORANGE)$@$(RESET)  $(NAME) $(GREEN)[OK]$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(RED)$@$(RESET) $(NAME) $(GREEN)[OK]$(RESET)"

re: fclean all

run: all
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --track-fds=yes --suppressions=ignore_readline.supp ./minishell

.PHONY: all clean fclean re
