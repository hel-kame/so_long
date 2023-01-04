/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:02:22 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/04 18:12:07 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_cross_x(t_mlx *m, int x, int y)
{
	int	tmp_x;

	tmp_x = x;
	while (m->map[x][y] != '1' && x <= m->row)
	{
		m->map[x][y] = '*';
		x++;
	}
	x = tmp_x;
	while (m->map[x][y] != '1' && x >= 0)
	{
		m->map[x][y] = '*';
		x--;
	}
	x = tmp_x;
}

static void	init_cross_y(t_mlx *m, int x, int y)
{
	int	tmp_y;

	tmp_y = y;
	while (m->map[x][y] != '1' && y >= 0)
	{
		m->map[x][y] = '*';
		y--;
	}
	y = tmp_y;
	while (m->map[x][y] != '1' && y <= m->column)
	{
		m->map[x][y] = '*';
		y++;
	}
	y = tmp_y;
}

void	init_cross(t_mlx *m, int x, int y)
{
	init_cross_x(m, x, y);
	init_cross_y(m, x, y);
}
