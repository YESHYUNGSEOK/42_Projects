# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 11:37:37 by hyungnoh          #+#    #+#              #
#    Updated: 2022/12/13 16:37:37 by hyungnoh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECT = so_long.o \
get_next_line_utils.o \
get_next_line.o \

PRINTF = ft_printf

NAME = so_long

HEADER = ./

COMPILE_YET = cc -Wall -Wextra -Werror

all : $(NAME)
	
$(NAME) : $(OBJECT)
	ar rcs $(NAME) $(OBJECT) 

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