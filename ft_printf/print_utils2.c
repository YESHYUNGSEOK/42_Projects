/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:37:16 by hyungseok         #+#    #+#             */
/*   Updated: 2022/12/13 15:10:35 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(va_list *ap)
{
	int		cnt;
	size_t	num;

	cnt = 0;
	num = va_arg(*ap, unsigned int);
	ft_putunsigned(num, &cnt);
	return (cnt);
}

int	print_x(va_list *ap)
{
	int		cnt;
	size_t	num;

	cnt = 0;
	num = va_arg(*ap, unsigned int);
	ft_puthex(num, &cnt);
	return (cnt);
}

int	print_bx(va_list *ap)
{
	int		cnt;
	size_t	num;

	cnt = 0;
	num = va_arg(*ap, unsigned int);
	ft_putbighex(num, &cnt);
	return (cnt);
}

int	print_per(void)
{
	if (write(1, "%", 1) == W_ERROR)
		return (W_ERROR);
	return (1);
}
