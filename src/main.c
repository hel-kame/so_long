/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:16:10 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/04 18:33:44 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	(void)argc;
	init_map(argv[1], &mlx);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
	{
		free(mlx.mlx);
		exit(-1);
	}
	mlx_win_init(&mlx);
	mlx_hook_init(mlx);
	mlx_loop(mlx.mlx);
	destroy_all_images(&mlx, 4);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
	free_map(&mlx);
}
