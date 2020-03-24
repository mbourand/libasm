# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 15:50:28 by mbourand          #+#    #+#              #
#    Updated: 2020/02/06 13:42:56 by mbourand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libasm.a
CC		= nasm
CFLAGS	= -f elf64
SRC_PATH= srcs/
OBJ_PATH= objs/

SRC_NAME= ft_strlen.s ft_strcpy.s ft_read.s ft_write.s ft_strdup.s
OBJ_NAME= $(SRC_NAME:.s=.o)
TESTER_PATH= test.c

INC= -I incs/
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB= libasm.a

DEF= \033[0m
RED= \033[31;1m
GRN= \033[32;1m
YEL= \033[33;1m

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(RED)[libasm] : $(DEF)Compilation..."
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(RED)[libasm] : $(DEF)Compilation                 $(GRN)[OK]$(DEF)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.s
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED)[libasm] :$(DEF) Compiling $@"
	@$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[libasm] : $(DEF)Cleaning           $(GRN)[OK]$(DEF)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)[libasm] : $(DEF)Full Cleaning       $(GRN)[OK]$(DEF)"

re: fclean all

run: all
	@echo "$(RED)[libasm] :$(DEF) Compiling $(TESTER_PATH)"
	@gcc -fsanitize=address -g $(TESTER_PATH) $(NAME)
	@echo "$(GRN)Running..."
	@./a.out
