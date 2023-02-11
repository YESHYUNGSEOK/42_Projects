/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:37:16 by hyungseok         #+#    #+#             */
/*   Updated: 2022/12/01 21:07:57 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(va_list *ap)
{
	unsigned char	c;

	c = va_arg(*ap, int);
	if (write (1, &c, 1) == W_ERROR)
		return (W_ERROR);
	return (1);
}

int	print_s(va_list *ap)
{
	int		cnt;
	char	*str;

	cnt = 0;
	str = va_arg(*ap, char *);
	if (!str)
	{
		if (write(1, "(null)", 6) == W_ERROR)
			return (W_ERROR);
		return (6);
	}
	while (*str)
	{
		if (write(1, &(*str), 1) == W_ERROR)
			return (W_ERROR);
		str++;
		cnt++;
	}
	return (cnt);
}

int	print_p(va_list *ap)
{
	int		cnt;
	size_t	address;

	cnt = 0;
	address = va_arg(*ap, size_t);
	if (write(1, "0x", 2) == W_ERROR)
		return (W_ERROR);
	cnt += 2;
	ft_puthex(address, &cnt);
	return (cnt);
}

int	print_d(va_list *ap)
{
	int	cnt;
	int	num;

	cnt = 0;
	num = va_arg(*ap, int);
	if (num == -2147483648)
		ft_int_min(&cnt);
	else
	{
		if (num < 0)
		{
			if (write(1, "-", 1) == W_ERROR)
			{
				cnt = W_ERROR;
				return (cnt);
			}
			num = -num;
			cnt += 1;
		}
		ft_putnbr(num, &cnt);
	}
	return (cnt);
}

int	print_i(va_list *ap)
{
	int	cnt;
	int	num;

	cnt = 0;
	num = va_arg(*ap, int);
	if (num == -2147483648)
		ft_int_min(&cnt);
	else
	{
		if (num < 0)
		{
			if (write(1, "-", 1) == W_ERROR)
			{
				cnt = W_ERROR;
				return (cnt);
			}
			num = -num;
			cnt += 1;
		}
		ft_putnbr(num, &cnt);
	}
	return (cnt);
}
