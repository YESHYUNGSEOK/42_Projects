# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 21:43:20 by hyungnoh          #+#    #+#              #
#    Updated: 2023/02/16 14:05:07 by hyungnoh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECT = philo.o \
utils.o \
philo_utils.o \
init.o \
congression.o \
actions.o \
eating.o

NAME = philo

HEADER = ./

COMPILE_YET = cc -Wall -Wextra -Werror

all : $(NAME)
	
$(NAME) : $(OBJECT)
	$(COMPILE_YET) -o $(NAME) $(OBJECT)

%.o : %.c
	$(COMPILE_YET) -I $(HEADER) -c $^ -o $@ -g

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re