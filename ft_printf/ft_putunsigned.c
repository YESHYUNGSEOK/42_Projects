/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:15:00 by hyungnoh          #+#    #+#             */
/*   Updated: 2022/12/01 17:56:31 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(size_t n, int *cnt)
{
	if (*cnt == W_ERROR)
		return ;
	if (n > 9)
	{
		ft_putunsigned(n / 10, cnt);
		ft_putunsigned(n % 10, cnt);
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
