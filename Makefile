# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jobject <jobject@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 21:38:45 by jobject           #+#    #+#              #
#    Updated: 2023/10/11 16:11:20 by jobject          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a
NAME_TEST	=	libasm_test

NASM		=	nasm
NASM_FLAG	=	-f elf64
CC			=	gcc
CC_FLAGS	=	-L. -lasm 

RM			= 	rm -rf
AR			=	ar rcs
RAN			=	ranlib

SRC			=	src/ft_strlen.s \
				src/ft_strcpy.s \
				src/ft_strcmp.s \
				src/ft_write.s \
				src/ft_read.s \
				src/ft_strdup.s
SRC_TEST	=	test/main.c

OBJ_DIR		=	.obj
OBJ			=	$(SRC:.s=.o)

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

test: re
	$(CC) $(SRC_TEST) $(CC_FLAGS) -o $(NAME_TEST)
	./$(NAME_TEST)
	@$(RM) $(NAME_TEST)