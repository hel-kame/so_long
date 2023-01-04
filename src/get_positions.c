/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:38:26 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/04 14:21:29 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_extension(char *filename)
{
	int	len;

	if (!filename)
		exit(-1);
	len = ft_strlen(filename);
	if (len <= 4)
		return (-1);
	if (ft_strcmp(".ber", filename + (len - 4)) != 0)
		return (-1);
	return (0);
}

int	get_first_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
		{
			free(str);
			return (-1);
		}
		i++;
	}
	return (0);
}

void	get_player_position(t_mlx *m)
{
	int	i;
	int	y;

	i = 0;
	while (m->map[i] != NULL)
	{
		y = 0;
		while (m->map[i][y] != '\0')
		{
			if (m->map[i][y] == 'P')
			{
				m->pos_row = i;
				m->pos_column = y;
			}
			y++;
		}
		i++;
	}
}

void	get_exit_position(t_mlx *m)
{
	int	i;
	int	y;

	i = 0;
	while (m->map[i] != NULL)
	{
		y = 0;
		while (m->map[i][y] != '\0')
		{
			if (m->map[i][y] == 'E')
			{
				m->ex_row = i;
				m->ex_column = y;
			}
			y++;
		}
		i++;
	}
}
