# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rmaes <rmaes@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/13 17:19:52 by rmaes         #+#    #+#                  #
#    Updated: 2022/10/13 18:53:38 by rmaes         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_min.c ft_max.c ft_btw.c ft_is_atoi.c ft_abs.c ft_ultoa.c ft_atoul.c
OBJECTS = $(SOURCES:.c=.o)
BONUS_SOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)
HEADER = libft.h
CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = libft.a
TEST = test

all: $(NAME)

$(TEST): $(NAME) $(SOURCES_TEST)
	$(CC) -g -o $@ $^

$(NAME): $(OBJECTS) $(HEADER)
	@echo archving $@
	@ar -rcsu $@ $^

%.o: %.c
	@echo compiling $^
	@$(CC) -c $(CFLAGS) -o $@ $^

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJECTS) $(OBJECTS) $(HEADER) $(NAME)
	@echo "adding bonus to $(NAME)"
	@ar -rcsu $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

.PHONY: all clean fclean re bonus
