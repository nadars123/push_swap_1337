# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrais <nrais@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 02:19:41 by nrais             #+#    #+#              #
#    Updated: 2025/03/23 08:33:44 by nrais            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra #-fsanitize=address -g3
RM = rm -f

NAME 	= push_swap
HEADER  = push_swap.h

SRCS = push_swap.c $(wildcard commands/*.c) $(wildcard stack_management/*.c) $(wildcard errors/*.c) $(wildcard sorting/*.c) $(wildcard parsing/*.c)
OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean