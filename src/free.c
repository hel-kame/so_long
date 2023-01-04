/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:59:43 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/04 22:44:39 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reload_map(t_mlx *mlx)
{
	int	i;

	i = mlx->row;
	while (i >= 0)
	{
		free(mlx->map[i]);
		i--;
	}
	free(mlx->map);
}

void	free_map(t_mlx *mlx)
{
	int	i;

	i = mlx->row;
	while (i >= 0)
	{
		free(mlx->map[i]);
		i--;
	}
	free(mlx->map);
}

void	destroy_all_images(t_mlx *mlx, int i)
{
	while (i >= 0)
	{
		mlx_destroy_image(mlx->mlx, mlx->img[i]);
		i--;
	}
}

void	free_mlx(t_mlx *mlx, int i)
{
	destroy_all_images(mlx, i);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free_map(mlx);
	exit(0);
}

int	handle_destroy(t_mlx *mlx)
{
	destroy_all_images(mlx, 7);
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free_map(mlx);
	exit(0);
}
