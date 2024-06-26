# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yojablao <yojablao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/02 04:35:32 by yojablao          #+#    #+#              #
#    Updated: 2024/06/25 11:56:39 by yojablao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
SRC_DIR = src
HEAD = src/push_swap.h
OBJ_DIR = obj
LIBFT_DIR = libft

SRC_FILES = push_swap.c util.c sort.c s_rules.c s_push.c r_rules.c rr_rules.c stack.c  tools.c
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)


NAME = push_swap


all: $(OBJ_DIR) $(NAME) 


$(NAME): $(OBJ_FILES)  $(LIBFT_DIR)/libft.a
	$(CC) $(CFLAGS) $(LIBFT_DIR)/libft.a $^ -o $@


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)


push:
	git add .
	git commit -m "yojablao"
	git push
clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
