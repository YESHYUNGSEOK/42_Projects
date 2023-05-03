/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:16 by hyungnoh          #+#    #+#             */
/*   Updated: 2022/12/13 20:06:23 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>

#define W_KEY 13
#define A_KEY 0
#define S_KEY 1
#define D_KEY 2
#define ESC_KEY 53

typedef struct s_info
{
	int	x;
	int	y;
}	t_info;

void	info_init(t_info *point)
{
	point->x = 0;
	point->y = 0;
}

int	key_pressed(int key, t_info *point)
{
	if (key == W_KEY)
		point->x++;
	else if (key == S_KEY)
		point->x--;
	else if (key == A_KEY)
		point->y++;
	else if (key == D_KEY)
		point->y--;
	else if (key == ESC_KEY)
		exit(0);
	return (0);
}

int	main(void)
{
	t_info	point;
	void	*m_ptr;
	void	*w_ptr;
	void	*img_ptr;
	int		width;
	int		height;

	width = 1920;
	height = 1080;
	info_init(&point);
	m_ptr = mlx_init();
	w_ptr = mlx_new_window(m_ptr, 1920, 1080, "so_long");
	img_ptr = mlx_xpm_file_to_image(m_ptr, , &width, &height);
	mlx_put_image_to_window(m_ptr, w_ptr, img_ptr, 0, 0);
	mlx_key_hook(w_ptr, key_pressed, &point);
	mlx_loop(m_ptr);
	return (0);
}

//cc -I /usr/local/include/ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit main.c