/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:31:16 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/04 22:44:10 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(t_mlx *mlx)
{
	(void)mlx;
	return (0);
}

int	count_move(int keycode, t_mlx *m)
{
	if ((keycode == W && m->map[m->pos_row - 1][m->pos_column] != '1')
		|| (keycode == S && m->map[m->pos_row + 1][m->pos_column] != '1')
		|| (keycode == A && m->map[m->pos_row][m->pos_column - 1] != '1')
		|| (keycode == D && m->map[m->pos_row][m->pos_column + 1] != '1'))
		return (1);
	return (0);
}

int	handle_keypress(int keycode, t_mlx *mlx)
{
	static int	i;
	static int	colors;

	if (keycode == ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	if (keycode == W || keycode == S || keycode == A || keycode == D)
	{
		game_events(keycode, mlx);
		if (count_move(keycode, mlx))
		{
			i++;
			colors++;
			mlx->move = i;
			ft_printf("\t\e[1m\x1B[38;5;%dm%d\033[0m\n", colors, i);
		}
	}
	return (0);
}

void	mlx_hook_init(t_mlx mlx)
{
	mlx_loop_hook(mlx.mlx, &handle_no_event, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, &handle_destroy, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, &handle_keypress, &mlx);
}
