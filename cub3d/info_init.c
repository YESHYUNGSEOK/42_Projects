/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:28:59 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/22 18:47:26 by hyungnoh         ###   ########.fr       */
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
	check_wall(info->map);
	//위아래 모두 1
	//좌우 모두 1
	//그외 상하좌우 모두 0 or 1, 상하좌우 중 공백이 있으면 무조건 1
	close(info->fd);
}
