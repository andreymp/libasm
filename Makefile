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
NASM_FLAG	=	-f elf64
RM			= 	rm -rf
AR			=	ar rcs
RAN			=	ranlib

SRC			=	src/ft_strlen.s \
				src/ft_strcpy.s \
				src/ft_strcmp.s \

OBJ			=	$(SRC:.s=.o)
OBJ_DIR		=	.obj

.PHONY: all clean fclean re

$(OBJ_DIR)/%.o:	%.s Makefile
				@mkdir -p $(OBJ_DIR)
				@mkdir -p $(OBJ_DIR)/src

				$(NASM) $(NASM_FLAG) $<
				@mv src/*.o $(OBJ_DIR)/src


$(NAME): $(addprefix $(OBJ_DIR)/, $(OBJ))
	$(AR) $(NAME) $^


all: $(NAME)


clean:
	@$(RM) $(OBJ_DIR)


fclean: clean
	@$(RM) $(NAME)


re: fclean $(NAME)