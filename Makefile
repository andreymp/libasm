# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jobject <jobject@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 21:38:45 by jobject           #+#    #+#              #
#    Updated: 2023/10/10 17:30:54 by jobject          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

NASM		=	nasm
NASM_FLAG	=	-f macho64
RM			= 	rm -rf

SRC			=	src/ft_strlen.s \
				src/ft_strcpy.s \
				src/ft_strcmp.s \

OBJ			=	$(SRC:.s=.o)
OBJ_DIR		=	.obj

.PHONY: all clean fclean re

all: $(NAME)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)