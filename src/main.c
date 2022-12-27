/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:16:10 by hel-kame          #+#    #+#             */
/*   Updated: 2022/12/27 21:27:08 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		exit(-1);
	mlx.win = mlx_new_window(mlx.mlx, 640, 480, "so_long");
	if (!mlx.win)
	{
		free(mlx.win);
		exit(-1);
	}
	mlx_hook_init(mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
}
