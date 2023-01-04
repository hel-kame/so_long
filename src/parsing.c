/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:43:28 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/04 22:43:00 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_info(char *filename, t_mlx *mlx)
{
	int		fd;
	char	*str;
	int		i;

	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
	if (fd < 0 || !str)
		return (-1);
	mlx->column = ft_strlen(str) - 1;
	i = 0;
	while (str)
	{
		i++;
		if (i == 1 && get_first_line(str) == -1)
			return (-1);
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
		if (y != mlx->column || mlx->map[i][y - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

void	init_map(char *filename, t_mlx *mlx)
{
	if (get_extension(filename))
		exit(ft_printf("\n\t\e[1m\x1B[38;5;196mBad extension ! \n\n"));
	if (get_map_info(filename, mlx) == -1)
		exit(ft_printf("\n\t\e[1m\x1B[38;5;196mMap Error ! \n\n"));
	stock_map(filename, mlx);
	if (check_map(mlx) == -1 || check_cmp(mlx) == -1)
	{
		free_map(mlx);
		exit(ft_printf("\n\t\e[1m\x1B[38;5;196mMap Error !\n\n"));
	}
	pathfinding(filename, mlx);
	get_exit_position(mlx);
	mlx->current_c = 0;
	mlx->move = 0;
	mlx->map[mlx->ex_row][mlx->ex_column] = '0';
}
