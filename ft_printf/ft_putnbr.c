/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:15:00 by hyungnoh          #+#    #+#             */
/*   Updated: 2022/12/01 19:37:29 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *cnt)
{
	if (*cnt == W_ERROR)
		return ;
	if (n > 9)
	{
		ft_putnbr(n / 10, cnt);
		ft_putnbr(n % 10, cnt);
	}
	else
	{
		if (write(1, &"0123456789"[n], 1) == W_ERROR)
		{
			*cnt = W_ERROR;
			return ;
		}
			*cnt += 1;
	}
}
