/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:15:00 by hyungnoh          #+#    #+#             */
/*   Updated: 2022/12/01 19:10:14 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(size_t n, int *cnt)
{
	if (*cnt == W_ERROR)
		return ;
	if (n >= 16)
	{
		ft_puthex(n / 16, cnt);
		ft_puthex(n % 16, cnt);
	}
	else
	{
		if (write(1, &"0123456789abcdef"[n], 1) == W_ERROR)
		{
			*cnt = W_ERROR;
			return ;
		}
		*cnt += 1;
	}
}
