/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:41:34 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/01 21:04:47 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_image(t_mlx *m)
{
	int	i;

	m->win = mlx_new_window(m->mlx, (m->column * 32), (m->row * 32), "so_long");
	if (!m->win)
	{
		free(m->win);
		exit(-1);
	}
	m->p_img = mlx_xpm_file_to_image(m->mlx, "./src/p.xpm", &i, &i);
	m->e_img = mlx_xpm_file_to_image(m->mlx, "./src/e.xpm", &i, &i);
	m->w_img = mlx_xpm_file_to_image(m->mlx, "./src/1.xpm", &i, &i);
	m->g_img = mlx_xpm_file_to_image(m->mlx, "./src/0.xpm", &i, &i);
	m->c_img = mlx_xpm_file_to_image(m->mlx, "./src/c.xpm", &i, &i);
}

void	map_to_image(t_mlx *m)
{
	int	i;
	int	y;

	i = 0;
	while (m->map[i] != NULL)
	{
		y = 0;
		while (m->map[i][y] != '\0')
		{
			if (m->map[i][y] == 'P')
				mlx_put_image_to_window(m->mlx, m->win, m->p_img, (y * 32), (i * 32));
			if (m->map[i][y] == 'E')
				mlx_put_image_to_window(m->mlx, m->win, m->e_img, (y * 32), (i * 32));
			if (m->map[i][y] == '1')
				mlx_put_image_to_window(m->mlx, m->win, m->w_img, (y * 32), (i * 32));
			if (m->map[i][y] == '0')
				mlx_put_image_to_window(m->mlx, m->win, m->g_img, (y * 32), (i * 32));
			if (m->map[i][y] == 'C')
				mlx_put_image_to_window(m->mlx, m->win, m->c_img, (y * 32), (i * 32));
			y++;
		}
		i++;
	}
}

void	mlx_win_init(t_mlx *mlx)
{
	create_image(mlx);
	map_to_image(mlx);
}
