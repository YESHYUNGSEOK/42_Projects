# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 11:18:13 by hyungnoh          #+#    #+#              #
#    Updated: 2023/03/13 13:38:34 by hyungnoh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECT = phonebook.o

NAME = phonebook

HEADER = ./

COMPILE_YET = c++ -Wall -Wextra -Werror

all : $(NAME)
	
$(NAME) : $(OBJECT)
	$(COMPILE_YET) -o $(NAME) $(OBJECT)

%.o : %.cpp
	$(COMPILE_YET) -I $(HEADER) -c $^ -o $@

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re