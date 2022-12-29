/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:16:10 by hel-kame          #+#    #+#             */
/*   Updated: 2022/12/29 01:03:21 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	int		img_width = 1;
	int		img_heigh = 1;

	(void)argc;
	init_map(argv[1], &mlx);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		exit(-1);
	mlx.win = mlx_new_window(mlx.mlx, 640, 480, "so_long");
	mlx.P_img = mlx_xpm_file_to_image(mlx.mlx, "./src/sprite.xpm", &img_width, &img_heigh);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.P_img, 32, 32);
	if (!mlx.win)
	{
		free(mlx.win);
		exit(-1);
	}
	mlx_hook_init(mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_image(mlx.mlx, mlx.P_img);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
}
