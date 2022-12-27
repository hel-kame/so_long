/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:16:10 by hel-kame          #+#    #+#             */
/*   Updated: 2022/12/27 20:37:51 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(t_mlx *mlx)
{
	(void)mlx;
	return (0);
}

int	close_window(t_mlx *mlx)
{
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
		ft_printf("Nombre de move = %d\n", mlx->move);
	}
	return (0);
}

int	main(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (!mlx.mlx)
	{
		free(mlx.mlx);
		exit(-1);
	}
	mlx.win = mlx_new_window(mlx.mlx, 640, 480, "Hello World");
	if (!mlx.win)
		exit(-1);
	mlx_loop_hook(mlx.mlx, &handle_no_event, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, &close_window, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, &handle_keypress, &mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
}
