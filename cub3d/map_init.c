/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:05:41 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/20 14:52:41 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_validity(char *line)
{
	int	i;

	i = -1;
	while (line[++i] != '\0' && line[i] != '\n')
	{
		if (line[i] == '1' || line[i] == '0')
			return (1);
	}
	return (0);
}

void	map_start(t_info *info)
{
	char	*line;

	while (READ_MAP)
	{
		line = get_next_line(info->fd);
		if (check_validity(line))
		{
			info->map = malloc(sizeof(t_map));
			info->map->line = ft_linedup(line);
			info->map->prev = NULL;
			info->map->next = NULL;
			free(line);
			return ;
		}
		free(line);
	}
	err_msg("error : invalid map");
}

void	map_init(t_info *info)
{
	char	*line;
	t_map	*cur;
	t_map	*next;

	map_start(info);
	cur = info->map;
	next = info->map->next;
	while (READ_MAP)
	{
		line = get_next_line(info->fd);
		if (line == NO_MORE_TO_READ)
		{
			free(line);
			break ;
		}
		next = malloc(sizeof(t_map));
		next->line = ft_linedup(line);
		next->prev = cur;
		next->next = NULL;
		cur->next = next;
		cur = cur->next;
		next = next->next;
		free(line);
	}
}