# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 17:30:47 by arasal            #+#    #+#              #
#    Updated: 2022/05/06 03:02:12 by arasal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Disable built-in rules and variables
MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables

# Compiler Variables
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB1 = ar -rcs
RM = rm -f
INCLUDE = ft_printf.h

# File Variables
NAME = libftprintf.a
SOURCES =	ft_printf.c ft_flags.c ft_hexadecimals.c ft_pointers.c ft_alphabets.c \
			ft_numbers.c ft_numbers_unsigned.c ft_strlen.c ft_itoa.c ft_itoa_first.c \
			ft_strjoin.c ft_calloc.c ft_strchr.c ft_atoi.c ft_putstr_fd.c
OBJECTS =	$(SOURCES:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
	$(LIB1) $(NAME)	$(OBJECTS)

.o: .c
	$(CC) -c $(CFLAGS) $(SOURCES) -I $(INCLUDE) -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM)	$(NAME)

re: fclean all

.PHONY: all clean fclean re
