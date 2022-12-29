/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:43:28 by hel-kame          #+#    #+#             */
/*   Updated: 2022/12/29 00:56:42 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_info(char *filename, t_mlx *mlx)
{
	int		fd;
	char	*str;
	int		i;

	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
	if (!str || fd < 0)
		return ;
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

int	check_compose(t_mlx *mlx)
{
	int		i;
	int		y;
	int		P;
	int		C;
	int		E;

	i = 0;
	P = 0;
	C = 0;
	E = 0;
	while (mlx->map[i] != NULL)
	{
		y = 0;
		while (mlx->map[i][y] != '\0')
		{
			if (mlx->map[i][y] == 'P')
				P++;
			if (mlx->map[i][y] == 'C')
				C++;
			if (mlx->map[i][y] == 'E')
				E++;
			y++;
		}
		i++;
	}
	if (P != 1 || E != 1 || C == 0)
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
	exit(-1);
}

void	init_map(char *filename, t_mlx *mlx)
{
	get_map_info(filename, mlx);
	stock_map(filename, mlx);
	if (check_map(mlx) == -1 || check_compose(mlx) == -1)
	{
		ft_printf("Map Error\n");
		free_map(mlx);
	}
}
