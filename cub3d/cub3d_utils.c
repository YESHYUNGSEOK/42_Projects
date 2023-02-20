/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:25:42 by hyungseok         #+#    #+#             */
/*   Updated: 2023/02/20 15:05:14 by hyungnoh         ###   ########.fr       */
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

int	elements_filled(int elements_cnt[])
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (elements_cnt[i] != FILLED)
			return (0);
	}
	return (1);
}

void	free_all(t_info *info)
{
	free(info->north_path);
	free(info->south_path);
	free(info->west_path);
	free(info->east_path);
	free(info->map);
}