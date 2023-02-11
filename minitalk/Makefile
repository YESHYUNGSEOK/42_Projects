# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 11:37:37 by hyungnoh          #+#    #+#              #
#    Updated: 2023/01/09 15:47:19 by hyungnoh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECT_S = server.o \
ft_putnbr_fd.o \
ft_putstr_fd.o \

OBJECT_C = client.o \
ft_atoi.o

NAME_S = server

NAME_C = client

HEADER = ./

COMPILE_YET = cc -Wall -Wextra -Werror -g

all : $(NAME_S) $(NAME_C)
	
$(NAME_S) : $(OBJECT_S)
	$(COMPILE_YET) -o $(NAME_S) $(OBJECT_S)

$(NAME_C) : $(OBJECT_C)
	$(COMPILE_YET) -o $(NAME_C) $(OBJECT_C)

%.o : %.c
	$(COMPILE_YET) -I $(HEADER) -c $^ -o $@

clean :
	rm -f $(OBJECT_S) $(OBJECT_C)

fclean : clean
	rm -f $(NAME_S) $(NAME_C)

re :
	make fclean
	make all

.PHONY : all clean fclean re