RED						= \033[0;31m
GREEN					= \033[0;32m
YELLOW					= \033[0;33m
NO_COLOR				= \033[0m

CLIENT					= bin/client
SERVER					= bin/server
NAME					= $(SERVER) $(CLIENT)

CLIENT_DIR				= src/client
SERVER_DIR				= src/server
COMMON_DIR				= src/common
LIBFT_DIR 				= lib/libft
LIBFT 					= $(LIBFT_DIR)/libft.a
PRINTF_DIR 				= lib/printf
PRINTF 					= $(PRINTF_DIR)/printf.a

CC						= gcc
CFLAGS 					= -Wall -Werror -Wextra -Iincludes -I$(LIBFT_DIR) -I$(PRINTF_DIR)

CLIENT_FILES			= $(addprefix $(CLIENT_DIR)/,client.c handle_server_response.c \
							packet_message.c send_packet.c handle_input.c handle_timeout.c \
							reset_byte.c)
CLIENT_OBJECT_FILES		= $(CLIENT_FILES:$(CLIENT_DIR)/%.c=obj/%.o)

SERVER_FILES			= $(addprefix $(SERVER_DIR)/,ask_retransmission.c print_message.c \
							reset_state.c server.c handle_byte.c print_server_pid.c send_ack.c \
							show_banner.c handle_complete_packet.c reset_byte.c \
							send_collision_signal.c valid_checksum.c)
SERVER_OBJECT_FILES		= $(SERVER_FILES:$(SERVER_DIR)/%.c=obj/%.o)

COMMON_FILES			= $(addprefix $(COMMON_DIR)/,calculate_checksum.c initialize_sigaction.c)
COMMON_OBJECT_FILES		= $(COMMON_FILES:$(COMMON_DIR)/%.c=obj/%.o)

all: $(NAME)

$(SERVER): $(LIBFT) $(PRINTF) $(COMMON_OBJECT_FILES) $(SERVER_OBJECT_FILES) includes/common.h includes/server.h
	@echo "${YELLOW}Linking $(SERVER)...${NO_COLOR}"
	@mkdir -p bin
	@$(CC) $(CFLAGS) -o $(SERVER) $(COMMON_OBJECT_FILES) $(SERVER_OBJECT_FILES) $(LIBFT) $(PRINTF)

$(CLIENT): $(LIBFT) $(PRINTF) $(COMMON_OBJECT_FILES) $(CLIENT_OBJECT_FILES) includes/common.h includes/client.h
	@echo "${YELLOW}Linking $(CLIENT)...${NO_COLOR}"
	@mkdir -p bin
	@$(CC) $(CFLAGS) -o $(CLIENT) $(COMMON_OBJECT_FILES) $(CLIENT_OBJECT_FILES) $(LIBFT) $(PRINTF)

$(LIBFT):
	@echo "${GREEN}Making libft...${NO_COLOR}"
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@echo "${GREEN}Making printf...${NO_COLOR}"
	@$(MAKE) -C $(PRINTF_DIR)

obj/%.o: $(CLIENT_DIR)/%.c includes/common.h includes/client.h
	@echo "${YELLOW}Compiling $<...${NO_COLOR}"
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: $(SERVER_DIR)/%.c includes/common.h includes/server.h
	@echo "${YELLOW}Compiling $<...${NO_COLOR}"
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: $(COMMON_DIR)/%.c includes/common.h
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