/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:46:25 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/01 20:32:07 by hel-kame         ###   ########.fr       */
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
	int		pos_row;
	int		pos_column;
	void	*mlx;
	void	*win;
	int		width;
	int		heigh;
	char	**map;
	void	*g_img;
	void	*w_img;
	void	*p_img;
	void	*c_img;
	void	*e_img;
}			t_mlx;

typedef struct s_compose {
	int	i;
	int	y;
	int	p;
	int	c;
	int	e;
}		t_compose;

int		handle_no_event(t_mlx *mlx);
int		handle_destroy(t_mlx *mlx);
int		handle_keypress(int keycode, t_mlx *mlx);
void	mlx_hook_init(t_mlx mlx);
void	get_map_info(char *filename, t_mlx *mlx);
int		check_compose(t_mlx *mlx);
int		check_map(t_mlx *mlx);
void	stock_map(char *filename, t_mlx *mlx);
void	init_map(char *filename, t_mlx *mlx);
void	free_map(t_mlx *mlx);
void	create_image(t_mlx *mlx);
void	*c_to_img(char c, t_mlx *mlx);
void	map_to_image(t_mlx *mlx);
void	mlx_win_init(t_mlx *mlx);
void	get_position(t_mlx *mlx);
void	moove_player(int keycode, t_mlx *mlx);
void	game_events(int keycode, t_mlx *mlx);
#endif
