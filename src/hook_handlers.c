/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:06:28 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/01 20:31:39 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(t_mlx *mlx)
{
	(void)mlx;
	return (0);
}

int	handle_destroy(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->p_img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
}

int	handle_keypress(int keycode, t_mlx *mlx)
{
	static int	i;

	if (keycode == ESC)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (keycode == W || keycode == S || keycode == A || keycode == D)
	{
		i++;
		mlx->move = i;
		ft_printf("%d\n", mlx->move);
		game_events(keycode, mlx);
	}
	return (0);
}

void	mlx_hook_init(t_mlx mlx)
{
	mlx_loop_hook(mlx.mlx, &handle_no_event, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, &handle_destroy, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, &handle_keypress, &mlx);
}
