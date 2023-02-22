/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:47:58 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/22 19:47:50 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_last(t_map *map)
{
	t_map	*tmp;
	int		i;

	tmp = map;
	i = -1;
	while (tmp)
	{
		++i;
		tmp = tmp->next;
	}
	if (i < 2)
		err_msg("error : invalid map");
	return (i);
}

void	check_side(t_map *map, int i, int j, int last)
{
	t_map	*tmp;
	int		len;

	tmp = map;
	while (tmp)
	{
		if (tmp->line[0] != '1' && tmp->line[0] != ' ')
			err_msg("error : wall not closed");
		len = ft_strlen(tmp->line) - 1;
		if (tmp->line[len] != '1')
			err_msg("error : wall not closed");
		i = -1;
		while (tmp->line[++i])
		{
			if (j == 0 || j == last)
			{
				if (tmp->line[i] != '1' && tmp->line[i] != ' ')
					err_msg("error : wall not closed");
			}
		}
		j++;
		tmp = tmp->next;
	}	
}

void	check_closed(t_map *map, int i, int j, int last)
{
	t_map	*tmp;
	int		len;

	tmp = map;
	while (tmp)
	{
		len = ft_strlen(tmp->line) - 1;
		while (++i < len && j != 0 && j != last)
		{
			if ((tmp->line[i] != '1' && tmp->line[i] != ' ') 
				&& (tmp->line[i - 1] == ' ' || tmp->line[i + 1] == ' '
				|| tmp->prev->line[i] == ' ' || tmp->next->line[i] == ' '))
				err_msg("error : wall not closed");
			if (tmp->line[i] != ' ' && tmp->line[i - 1] == ' '
				&& tmp->line[i + 1] == ' ' && tmp->prev->line[i] == ' '
				&& tmp->next->line[i] == ' ')
				err_msg("error : wall not closed");
		}
		i = 0;
		j++;
		tmp = tmp->next;
	}
}

void	check_wall(t_map *map)
{
	int		last;

	last = get_last(map);
	check_side(map, -1, 0, last);
	check_closed(map, 0, 0, last);
}
