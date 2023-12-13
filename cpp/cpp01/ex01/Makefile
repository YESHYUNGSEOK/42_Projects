# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 11:18:13 by hyungnoh          #+#    #+#              #
#    Updated: 2023/12/12 14:05:56 by hyungseok        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECT = Zombie.o zombieHorde.o main.o

NAME = ZombieHorde

COMPILE = c++ -Wall -Werror -Wextra -std=c++98

all : $(NAME)
	
$(NAME) : $(OBJECT)
	$(COMPILE) -o $(NAME) $(OBJECT)

%.o : %.cpp
	$(COMPILE) -c $^ -o $@

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re