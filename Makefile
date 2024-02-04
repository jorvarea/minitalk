RED						= \033[0;31m
GREEN					= \033[0;32m
YELLOW					= \033[0;33m
NO_COLOR				= \033[0m

CLIENT					= client
SERVER					= server
NAME					= bin/$(SERVER) bin/$(CLIENT)

UTILS_DIR				= src/minishell_utils
LIBFT_DIR 				= lib/libft
LIBFT 					= $(LIBFT_DIR)/libft.a
PRINTF_DIR 				= lib/printf
PRINTF 					= $(PRINTF_DIR)/printf.a

CC						= gcc
CFLAGS 					= -Wall -Werror -Wextra -Iincludes -I$(LIBFT_DIR) -I$(PRINTF_DIR)

UTILS_FILES				= $(wildcard $(UTILS_DIR)/*.c) # Change this before sending
UTILS_OBJECT_FILES		= $(UTILS_FILES:$(UTILS_DIR)/%.c=obj/%.o)

all: $(NAME)

$(SERVER): $(LIBFT) $(PRINTF) $(UTILS_OBJECT_FILES) src/server.c includes/minishell_utils.h
	@echo "${YELLOW}Linking $(SERVER)...${NO_COLOR}"
	@mkdir -p bin
	@$(CC) $(CFLAGS) -o bin/$(SERVER) src/server.c $(UTILS_OBJECT_FILES) $(LIBFT) $(PRINTF)

$(CLIENT): $(LIBFT) $(UTILS_OBJECT_FILES) src/client.c includes/minishell_utils.h
	@echo "${YELLOW}Linking $(CLIENT)...${NO_COLOR}"
	@mkdir -p bin
	@$(CC) $(CFLAGS) -o bin/$(CLIENT) src/client.c $(UTILS_OBJECT_FILES) $(LIBFT) $(PRINTF)

$(LIBFT):
	@echo "${GREEN}Making libft...${NO_COLOR}"
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@echo "${GREEN}Making printf...${NO_COLOR}"
	@$(MAKE) -C $(PRINTF_DIR)

obj/%.o: $(UTILS_DIR)/%.c
	@echo "${YELLOW}Compiling $<...${NO_COLOR}"
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "${RED}Cleaning object files...${NO_COLOR}"
	@rm -rf obj
	@echo "${RED}Cleaning libraries...${NO_COLOR}"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	
fclean: clean
	@echo "${RED}Removing binaries...${NO_COLOR}"
	@rm -rf bin
	@echo "${RED}Fcleaning libraries...${NO_COLOR}"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re bonus