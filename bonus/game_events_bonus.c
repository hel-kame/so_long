/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:22:53 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/06 16:54:05 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	swap_elements(t_mlx *m, int row, int column)
{
	char	tmp;

	tmp = m->map[m->pos_row][m->pos_column];
	m->map[m->pos_row][m->pos_column] = m->map[row][column];
	m->map[row][column] = tmp;
}

void	moove_player(int keycode, t_mlx *m)
{
	if (keycode == W && m->map[m->pos_row - 1][m->pos_column] != '1')
		swap_elements(m, m->pos_row - 1, m->pos_column);
	if (keycode == S && m->map[m->pos_row + 1][m->pos_column] != '1')
		swap_elements(m, m->pos_row + 1, m->pos_column);
	if (keycode == D && m->map[m->pos_row][m->pos_column + 1] != '1')
		swap_elements(m, m->pos_row, m->pos_column + 1);
	if (keycode == A && m->map[m->pos_row][m->pos_column - 1] != '1')
		swap_elements(m, m->pos_row, m->pos_column - 1);
	if (m->current_c == m->nb_c)
		m->map[m->ex_row][m->ex_column] = 'E';
}

void	recolt_collectible(int keycode, t_mlx *m)
{
	if (keycode == D && m->map[m->pos_row][m->pos_column + 1] == 'C')
	{
		m->map[m->pos_row][m->pos_column + 1] = '0';
		m->current_c++;
	}
	if (keycode == A && m->map[m->pos_row][m->pos_column - 1] == 'C')
	{
		m->map[m->pos_row][m->pos_column - 1] = '0';
		m->current_c++;
	}
	if (keycode == S && m->map[m->pos_row + 1][m->pos_column] == 'C')
	{
		m->map[m->pos_row + 1][m->pos_column] = '0';
		m->current_c++;
	}
	if (keycode == W && m->map[m->pos_row - 1][m->pos_column] == 'C')
	{
		m->map[m->pos_row - 1][m->pos_column] = '0';
		m->current_c++;
	}
}

void	exit_game(int keycode, t_mlx *m)
{
	if (keycode == A && m->map[m->pos_row][m->pos_column - 1] == 'E')
	{
		success_message();
		free_mlx(m, 9);
	}
	if (keycode == D && m->map[m->pos_row][m->pos_column + 1] == 'E')
	{
		success_message();
		free_mlx(m, 9);
	}
	if (keycode == S && m->map[m->pos_row + 1][m->pos_column] == 'E')
	{
		success_message();
		free_mlx(m, 9);
	}
	if (keycode == W && m->map[m->pos_row - 1][m->pos_column] == 'E')
	{
		success_message();
		free_mlx(m, 9);
	}
}

void	game_events(int keycode, t_mlx *mlx)
{
	get_player_position(mlx);
	recolt_collectible(keycode, mlx);
	exit_game(keycode, mlx);
	encounter_ennemy(keycode, mlx);
	moove_player(keycode, mlx);
	map_to_image(mlx, keycode);
}
