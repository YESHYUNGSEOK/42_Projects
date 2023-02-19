/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungseok <hyungseok@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:25:43 by hyungseok         #+#    #+#             */
/*   Updated: 2023/02/19 17:45:24 by hyungseok        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define OPEN_ERROR -1

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}	t_map;

typedef struct s_info
{
	char			*n_path;
	char			*s_path;
	char			*w_path;
	char			*e_path;
	int				f_rgb[3];
	int				c_rgb[3];
	struct s_map	*map;
}	t_info;

//cub3d
int		check_arg(char *filename);
void	err_msg(char *s);
void	info_init(t_info *info, char *filename);
//utils
int		ft_strcmp(char *s1, char *s2);

//get_next_line
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);

#endif