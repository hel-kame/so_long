/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_img_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:24:00 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/06 09:48:08 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*player_to_img(char c, t_mlx *m, int keycode)
{
	if (keycode == 0 || keycode == S || keycode == W || keycode == D)
	{
		if (m->move % 2 == 0 && c == 'P')
			return (m->img[0]);
		else if (m->move % 2 != 0 && c == 'P')
			return (m->img[1]);
	}
	if (keycode == S || keycode == W || keycode == A)
	{
		if (m->move % 2 != 0 && c == 'P')
			return (m->img[2]);
		else if (m->move % 2 == 0 && c == 'P')
			return (m->img[3]);
	}
	return (0);
}

void	*elem_to_img(char c, t_mlx *m)
{
	if (c == 'E')
		return (m->img[4]);
	if (c == '1')
		return (m->img[5]);
	if (c == '0')
		return (m->img[6]);
	if (c == 'C')
		return (m->img[7]);
	return (0);
}

void	*ennemy_to_img(char c, t_mlx *m)
{
	if (m->ennemi < 5000 && c == 'X')
		return (m->img[8]);
	if (m->ennemi > 5000 && c == 'X')
		return (m->img[9]);
	return (0);
}
