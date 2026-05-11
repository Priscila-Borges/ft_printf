# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pride-ol <pride-ol@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2026/05/04 10:32:09 by pride-ol      #+#    #+#                  #
#    Updated: 2026/05/10 22:52:15 by pride-ol      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME: libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft

# libft variables
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)
$(LIBFT):
	make -C $(LIBFT_DIR)
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
re: fclean all
.PHONY: all re clean fclean