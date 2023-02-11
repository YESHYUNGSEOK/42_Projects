# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 11:37:37 by hyungnoh          #+#    #+#              #
#    Updated: 2023/01/03 19:41:54 by hyungnoh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECT = push_swap.o \
deque_utils.o \
swap_utils_1.o \
swap_utils_2.o \
swap_utils_3.o \
sort.o \
check_sorted.o \
divide_three.o \
sort_greedy.o \
find_best.o \
final_sort.o \
ft_atoi.o \
absolute.o \
check_av.o

NAME = push_swap

HEADER = ./

COMPILE_YET = cc -Wall -Wextra -Werror

all : $(NAME)
	
$(NAME) : $(OBJECT)
	$(COMPILE_YET) -o $(NAME) $(OBJECT)

%.o : %.c
	$(COMPILE_YET) -I $(HEADER) -c $^ -o $@

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re