/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:58:02 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/06 09:01:37 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	encounter_ennemy(int keycode, t_mlx *m)
{
	if (keycode == A && m->map[m->pos_row][m->pos_column - 1] == 'X')
	{
		fail_message();
		free_mlx(m, 9);
	}
	if (keycode == D && m->map[m->pos_row][m->pos_column + 1] == 'X')
	{
		fail_message();
		free_mlx(m, 9);
	}
	if (keycode == S && m->map[m->pos_row + 1][m->pos_column] == 'X')
	{
		fail_message();
		free_mlx(m, 9);
	}
	if (keycode == W && m->map[m->pos_row - 1][m->pos_column] == 'X')
	{
		fail_message();
		free_mlx(m, 9);
	}
}
