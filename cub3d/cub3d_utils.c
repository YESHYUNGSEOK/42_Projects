/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:25:42 by hyungseok         #+#    #+#             */
/*   Updated: 2023/02/19 17:54:08 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_arg(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5 || !ft_strcmp(filename + len - 4, ".cub"))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	info_init(t_info *info, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == OPEN_ERROR)
		err_msg("error : invalid map");
}
