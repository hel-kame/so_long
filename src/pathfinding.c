/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:29:18 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/06 17:37:45 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	explore_player_line(t_mlx *m)
{
	int	x;
	int	y;

	x = m->pos_row;
	y = m->pos_column;
	while (m->map[x][y] != '\0')
	{
		if (m->map[x][y] == '*')
			init_cross(m, x, y);
		y++;
	}
}

static void	explore_map(t_mlx *m)
{
	int	x;
	int	y;
	int	c;

	c = 0;
	while (c <= m->row * m->column)
	{
		x = 0;
		while (m->map[x] != NULL)
		{
			y = 0;
			while (m->map[x][y] != '\0')
			{
				if (m->map[x][y] == '*')
					init_cross(m, x, y);
				y++;
			}
			x++;
		}
		c++;
	}
}

static int	check_pathfinding(t_mlx *m)
{
	int		i;
	int		y;

	i = 0;
	while (m->map[i] != NULL)
	{
		y = 0;
		while (m->map[i][y] != '\0')
		{
			if ((m->map[i][y] == 'E') || (m->map[i][y] == 'C'))
				return (-1);
			y++;
		}
		i++;
	}
	return (0);
}

void	pathfinding(char *filename, t_mlx *m)
{
	get_player_position(m);
	init_cross(m, m->pos_row, m->pos_column);
	explore_player_line(m);
	explore_map(m);
	if (check_pathfinding(m) == -1)
	{
		ft_printf("\n\t\e[1m\x1B[38;5;196mPath is invalid !\033[0m\n\n");
		free_map(m);
		exit(-1);
	}
	reload_map(m);
	stock_map(filename, m);
}
