/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:28:59 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/21 19:57:52 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	info_init(t_info *info, char *filename)
{
	info->fd = open(filename, O_RDONLY);
	if (info->fd == OPEN_ERROR)
		err_msg("error : invalid map");
	elements_init(info);
	map_init(info);
	close(info->fd);
}
