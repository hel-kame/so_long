/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:58:02 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/05 21:32:53 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	encounter_ennemy(int keycode, t_mlx *m)
{
	if (keycode == A && m->map[m->pos_row][m->pos_column - 1] == 'X')
		free_mlx(m, 9);
	if (keycode == D && m->map[m->pos_row][m->pos_column + 1] == 'X')
		free_mlx(m, 9);
	if (keycode == S && m->map[m->pos_row + 1][m->pos_column] == 'X')
		free_mlx(m, 9);
	if (keycode == W && m->map[m->pos_row - 1][m->pos_column] == 'X')
		free_mlx(m, 9);
}

static void	*ennemy_image(char c, t_mlx *m, int i)
{
	if (i < 1000 && c == 'X')
		return (m->img[8]);
	if (i > 1000 && c == 'X')
		return (m->img[9]);
	return (0);
}

void	ennemy_in_map(t_mlx *m, int refresh)
{
	int	i;
	int	y;

	i = 0;
	while (m->map[i] != NULL)
	{
		y = 0;
		while (m->map[i][y] != '\0')
		{
			mlx_put_image_to_window(m->mlx, m->win,
				ennemy_image(m->map[i][y], m, refresh), (y * 50), (i * 50));
			y++;
		}
		i++;
	}
}
