# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 11:18:13 by hyungnoh          #+#    #+#              #
#    Updated: 2023/12/13 10:50:01 by hyungseok        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECT = Sed.o main.o

NAME = sed

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