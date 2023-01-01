/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:22:53 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/01 20:42:56 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_position(t_mlx *m)
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
			{
				m->pos_row = i;
				m->pos_column = y;
			}
			y++;
		}
		i++;
	}
}

void	moove_player(int keycode, t_mlx *m)
{
	char	tmp;

	if (keycode == W && m->map[m->pos_row - 1][m->pos_column] != '1')
	{
		tmp = m->map[m->pos_row][m->pos_column];
		m->map[m->pos_row][m->pos_column] = m->map[m->pos_row - 1][m->pos_column];
		m->map[m->pos_row - 1][m->pos_column] = tmp;
	}
	if (keycode == S && m->map[m->pos_row + 1][m->pos_column] != '1')
	{
		tmp = m->map[m->pos_row][m->pos_column];
		m->map[m->pos_row][m->pos_column] = m->map[m->pos_row + 1][m->pos_column];
		m->map[m->pos_row + 1][m->pos_column] = tmp;
	}
	if (keycode == D && m->map[m->pos_row][m->pos_column + 1] != '1')
	{
		tmp = m->map[m->pos_row][m->pos_column];
		m->map[m->pos_row][m->pos_column] = m->map[m->pos_row][m->pos_column + 1];
		m->map[m->pos_row][m->pos_column + 1] = tmp;
	}
	if (keycode == A && m->map[m->pos_row][m->pos_column - 1] != '1')
	{
		tmp = m->map[m->pos_row][m->pos_column];
		m->map[m->pos_row][m->pos_column] = m->map[m->pos_row][m->pos_column - 1];
		m->map[m->pos_row][m->pos_column - 1] = tmp;
	}
}

void	game_events(int keycode, t_mlx *mlx)
{
	int	i;
	int	y;

	i = 0;
	get_position(mlx);
	moove_player(keycode, mlx);
	while (mlx->map[i] != NULL)
	{
		y = 0;
		while (mlx->map[i][y] != '\0')
		{
			printf("%c", mlx->map[i][y]);
			y++;
		}
		printf("\n");
		i++;
	}
	map_to_image(mlx);
}
