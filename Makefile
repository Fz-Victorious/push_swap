# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/07 15:36:05 by fabou-za          #+#    #+#              #
#    Updated: 2022/08/16 12:34:50 by fabou-za         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc -Wall -Wextra -Werror
INC = push_swap.h
OBJ = check_and_create.o \
      operations.o \
      push_swap.o \
      utils.o \
	  stack_utils_one.o \
	  stack_utils_two.o \
	  sorting_small_stack.o \
      lis.o \
      not_in_lis.o \
      positions_in_stack_a.o \
	  positions_in_stack_b.o \
      finding_min_moves.o \
      moves_sorting_elem.o \
	  sort_a_from_min.o \
	  get_next_line_utils.o \
	  ft_split.o \
	  free_and_exit.o \

OBJ_BONUS = checker_bonus.o \
			checker_utils.o \
			checker_utils1.o \
			check_and_create.o \
			free_and_exit.o \
			stack_utils_one.o \
			stack_utils_two.o \
			operations.o \
			utils.o \
			get_next_line.o \
			get_next_line_utils.o \
			ft_split.o \

NAME = push_swap
NAME1 = checker

all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	$(CC) $(OBJ) -o $(NAME)

$(NAME1) : $(OBJ_BONUS) $(INC)
	$(CC) $(OBJ_BONUS) -o $(NAME1)

%.o : %.c $(INC)
	$(CC) -c $< -o $@

clean : 
	rm -f *.o

fclean : clean
	rm -rf $(NAME) $(NAME1)

re : fclean all

bonus : $(NAME1)
