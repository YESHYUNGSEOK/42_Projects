/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:25:49 by hyungseok         #+#    #+#             */
/*   Updated: 2023/02/20 15:07:24 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	leakss(void)
{
	system("leaks a.out");
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2 || check_arg(av[1]))
		err_msg("error : improper arguments");
	info_init(&info, av[1]);
	return (EXIT_SUCCESS);
}
