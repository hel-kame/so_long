/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:46:25 by hel-kame          #+#    #+#             */
/*   Updated: 2022/12/28 23:49:18 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307

typedef struct s_mlx {
	int		move;
	int		row;
	int		column;
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_heigh;
	char	**map;
	void	*G_img;
	void	*W_img;
	void	*P_img;
	void	*C_img;
	void	*E_img;
}			t_mlx;

int		handle_no_event(t_mlx *mlx);
int		handle_destroy(t_mlx *mlx);
int		handle_keypress(int keycode, t_mlx *mlx);
void	mlx_hook_init(t_mlx mlx);
void	get_map_info(char *filename, t_mlx *mlx);
void	stock_map(char *filename, t_mlx *mlx);
void	init_map(char *filename, t_mlx *mlx);
int		check_map(t_mlx *mlx);
#endif
