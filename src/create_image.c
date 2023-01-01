/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:41:34 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/01 20:42:07 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_image(t_mlx *m)
{
	m->win = mlx_new_window(m->mlx, (m->column * 32), (m->row * 32), "so_long");
	if (!m->win)
	{
		free(m->win);
		exit(-1);
	}
	m->p_img = mlx_xpm_file_to_image(m->mlx, "./src/p.xpm", &m->width, &m->heigh);
	m->e_img = mlx_xpm_file_to_image(m->mlx, "./src/e.xpm", &m->width, &m->heigh);
	m->w_img = mlx_xpm_file_to_image(m->mlx, "./src/1.xpm", &m->width, &m->heigh);
	m->g_img = mlx_xpm_file_to_image(m->mlx, "./src/0.xpm", &m->width, &m->heigh);
	m->c_img = mlx_xpm_file_to_image(m->mlx, "./src/c.xpm", &m->width, &m->heigh);
}

void	*c_to_img(char c, t_mlx *m)
{
	if (c == 'P')
		return (m->p_img);
	if (c == 'E')
		return (m->e_img);
	if (c == '1')
		return (m->w_img);
	if (c == '0')
		return (m->g_img);
	if (c == 'C')
		return (m->c_img);
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
			mlx_put_image_to_window(m->mlx, m->win, c_to_img(m->map[i][y], m), (y * 32), (i * 32));
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
