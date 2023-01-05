/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handlers_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:31:16 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/05 23:42:27 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_no_event(t_mlx *mlx)
{
	static int	i;

	i++;
	mlx->ennemi = i;
	if (i == 10000)
		i = 0;
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
	static unsigned int	i;
	int					*colors;

	colors = colors_values();
	mlx->display = ft_itoa(i);
	if (keycode == ESC)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (keycode == W || keycode == S || keycode == A || keycode == D)
	{
		game_events(keycode, mlx);
		if (count_move(keycode, mlx))
		{
			i++;
			mlx->move = i;
			ft_printf("\t\t\t\e[1m\x1B[38;5;%dm%d\033[0m\n", i, i);
		}
		mlx_string_put(mlx->mlx, mlx->win, 48, 56, colors[i], mlx->display);
	}
	free(mlx->display);
	return (0);
}

void	mlx_hook_init(t_mlx mlx)
{
	mlx_loop_hook(mlx.mlx, &handle_no_event, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, &handle_destroy, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, &handle_keypress, &mlx);
}
