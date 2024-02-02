# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jorvarea <jorvarea@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 18:05:05 by jorvarea          #+#    #+#              #
#    Updated: 2024/02/02 22:20:37 by jorvarea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= libft.a
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra
SOURCE_FILES   		= $(wildcard *.c) # Change this before sending
OBJECT_DIR 			= obj
OBJECT_FILES		= $(SOURCE_FILES:%.c=$(OBJECT_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJECT_FILES) libft.h
	@ar -rcs $(NAME) $(OBJECT_FILES)

$(OBJECT_DIR)/%.o: %.c
	@mkdir -p $(OBJECT_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECT_DIR)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re