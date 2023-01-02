/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:38:26 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/02 17:38:35 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
