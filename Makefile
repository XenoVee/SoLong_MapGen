# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rmaes <rmaes@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/08/01 13:10:16 by rmaes         #+#    #+#                  #
#    Updated: 2022/09/28 16:21:48 by rmaes         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SOURCES = sources/*.c sources/*/*.c
OBJECTS = $(SOURCES:.c=.o)
HEADER = mapgen.h
CFLAGS = -Wall -Wextra -Werror
CC = gcc
LIBFT = libft/libft.a
NAME = mapgen

all: $(NAME)

$(NAME): $(LIBFT) $(SOURCES)
	@echo "Compiling 'mapgen'"
	@$(CC) -g -o $@ $^

$(LIBFT):
	@echo 'Making libft'
	@make -C ./libft
	@make clean -C ./libft

clean:
	@echo "Removing mapgen"
	@rm -f $(OBJECTS) $(BONUS_OBJECTS)
	@rm -dfr $(NAME) $(NAME).dSYM

fclean: clean
	@echo "cleaning libft"
	@make fclean -C ./libft

re: clean all

fre: fclean re

.PHONY: all clean fclean re
