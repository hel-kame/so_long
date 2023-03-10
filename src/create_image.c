/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:41:34 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/06 14:57:48 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_image(t_mlx *m)
{
	static char	*path[5] = {"img/p.xpm", "img/e.xpm", "img/1.xpm",
		"img/0.xpm", "img/c.xpm"};

	m->win = mlx_new_window(m->mlx, (m->column * 50), (m->row * 50), "so_long");
	if (!m->win)
	{
		free(m->win);
		exit(-1);
	}
	init_image(m, path);
}

void	init_image(t_mlx *m, char **path)
{
	int	i;
	int	y;

	y = 0;
	while (y <= 4)
	{
		m->img[y] = mlx_xpm_file_to_image(m->mlx, path[y], &i, &i);
		if (y == 0 && !m->img[y])
		{
			mlx_destroy_window(m->mlx, m->win);
			mlx_destroy_display(m->mlx);
			free(m->mlx);
			free_map(m);
			exit(0);
		}
		else if (!m->img[y])
			free_mlx(m, y - 1);
		y++;
	}
}

void	*c_to_img(char c, t_mlx *m)
{
	if (c == 'P')
		return (m->img[0]);
	if (c == 'E')
		return (m->img[1]);
	if (c == '1')
		return (m->img[2]);
	if (c == '0')
		return (m->img[3]);
	if (c == 'C')
		return (m->img[4]);
	return (0);
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
			mlx_put_image_to_window(m->mlx, m->win,
				c_to_img(m->map[i][y], m), (y * 50), (i * 50));
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
