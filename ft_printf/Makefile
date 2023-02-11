# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 11:37:37 by hyungnoh          #+#    #+#              #
#    Updated: 2022/12/01 19:30:33 by hyungnoh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECT = ft_printf.o \
print_utils.o \
print_utils2.o \
ft_puthex.o \
ft_putbighex.o \
ft_putnbr.o \
ft_int_min.o \
ft_putunsigned.o

LIBFT = libft

NAME = libftprintf.a

HEADER = ./

COMPILE_YET = cc -Wall -Wextra -Werror

all : $(NAME)
	
$(NAME) : $(OBJECT)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a ./
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJECT) 

%.o : %.c
	$(COMPILE_YET) -I $(HEADER) -c $^ -o $@

libft :
	make all -C $(LIBFT)

clean :
	rm -f $(OBJECT)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a

re :
	make fclean
	make all

.PHONY : all clean fclean re