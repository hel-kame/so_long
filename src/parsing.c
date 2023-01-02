/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:43:28 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/02 19:09:07 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_info(char *filename, t_mlx *mlx)
{
	int		fd;
	char	*str;
	int		i;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
	if (fd < 0 || !str)
		return (-1);
	mlx->column = ft_strlen(str) - 1;
	i = 0;
	while (str)
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	mlx->row = i;
	return (0);
}

void	stock_map(char *filename, t_mlx *mlx)
{
	int		i;
	int		y;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	mlx->map = malloc(sizeof(char *) * (mlx->row + 1));
	if (!mlx->map)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		y = 0;
		while (line[y] != '\n' && line[y] != '\0')
			y++;
		line[y] = '\0';
		mlx->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	mlx->map[i] = NULL;
	close(fd);
}

int	check_cmp(t_mlx *mlx)
{
	t_compose	cmp;

	cmp.i = 0;
	cmp.p = 0;
	cmp.c = 0;
	cmp.e = 0;
	while (mlx->map[cmp.i] != NULL)
	{
		cmp.y = 0;
		while (mlx->map[cmp.i][cmp.y] != '\0')
		{
			if (mlx->map[cmp.i][cmp.y] == 'P')
				cmp.p++;
			if (mlx->map[cmp.i][cmp.y] == 'C')
				cmp.c++;
			if (mlx->map[cmp.i][cmp.y] == 'E')
				cmp.e++;
			cmp.y++;
		}
		cmp.i++;
	}
	mlx->nb_c = cmp.c;
	if (cmp.p != 1 || cmp.e != 1 || cmp.c == 0)
		return (-1);
	return (0);
}

int	check_map(t_mlx *mlx)
{
	int		i;
	int		y;

	i = 0;
	while (mlx->map[i] != NULL)
	{
		y = 0;
		while (mlx->map[i][y] != '\0')
		{
			if ((mlx->map[i][y] != '1') && (mlx->map[i][y] != '0') &&
					(mlx->map[i][y] != 'C') && (mlx->map[i][y] != 'E') &&
					(mlx->map[i][y] != 'P'))
				return (-1);
			if (((i == 0 || i == mlx->row - 1) && (mlx->map[i][y] != '1')) ||
					(mlx->map[i][0] != '1'))
				return (-1);
			y++;
		}
		if (mlx->map[i][y - 1] != '1' || y != mlx->column)
			return (-1);
		i++;
	}
	return (0);
}

void	init_map(char *filename, t_mlx *mlx)
{
	mlx->current_c = 0;
	if (get_map_info(filename, mlx) == -1)
		exit (-1);
	stock_map(filename, mlx);
	if (check_map(mlx) == -1 || check_cmp(mlx) == -1)
	{
		ft_printf("Map Error\n");
		free_map(mlx);
	}
	get_exit_position(mlx);
	mlx->map[mlx->ex_row][mlx->ex_column] = '0';
}
