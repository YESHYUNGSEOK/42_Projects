/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:27:56 by hyungnoh          #+#    #+#             */
/*   Updated: 2022/12/01 20:55:58 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conv_param(const char *str, va_list *ap)
{
	int	cnt;

	cnt = 0;
	if (*(str + 1) == 'c')
		cnt += print_c(ap);
	else if (*(str + 1) == 's')
		cnt += print_s(ap);
	else if (*(str + 1) == 'p')
		cnt += print_p(ap);
	else if (*(str + 1) == 'd')
		cnt += print_d(ap);
	else if (*(str + 1) == 'i')
		cnt += print_i(ap);
	else if (*(str + 1) == 'u')
		cnt += print_u(ap);
	else if (*(str + 1) == 'x')
		cnt += print_x(ap);
	else if (*(str + 1) == 'X')
		cnt += print_bx(ap);
	else if (*(str + 1) == '%')
		cnt += print_per();
	return (cnt);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		cnt;
	int		prev_cnt;

	va_start(ap, str);
	cnt = 0;
	while (*str)
	{
		prev_cnt = cnt;
		if (*str != '%')
			cnt += write(1, &(*str), 1);
		else if (*str == '%')
			cnt += conv_param(str++, &ap);
		if (prev_cnt > cnt)
		{
			va_end(ap);
			return (W_ERROR);
		}
		str++;
	}
	va_end(ap);
	return (cnt);
}
