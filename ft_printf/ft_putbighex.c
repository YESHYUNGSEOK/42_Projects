/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbighex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:15:00 by hyungnoh          #+#    #+#             */
/*   Updated: 2022/12/01 19:19:40 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbighex(size_t n, int *cnt)
{
	if (*cnt == W_ERROR)
		return ;
	if (n >= 16)
	{
		ft_putbighex(n / 16, cnt);
		ft_putbighex(n % 16, cnt);
	}
	else
	{
		if (write(1, &"0123456789ABCDEF"[n], 1) == W_ERROR)
		{
			*cnt = W_ERROR;
			return ;
		}
		*cnt += 1;
	}
}
