# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pride-ol <pride-ol@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2026/05/11 11:39:39 by pride-ol      #+#    #+#                  #
#    Updated: 2026/05/11 16:52:22 by pride-ol      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)	
	ar rcs $(NAME) $(OBJS)
%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)	
fclean: clean
	rm -f $(NAME)	
re: fclean all
.PHONY: all re clean fclean