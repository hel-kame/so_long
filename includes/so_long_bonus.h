/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:46:25 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/05 17:13:44 by hel-kame         ###   ########.fr       */
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
	unsigned int		move;
	int		row;
	int		column;
	int		pos_row;
	int		pos_column;
	int		ex_row;
	int		ex_column;
	int		nb_c;
	int		current_c;
	void	*mlx;
	void	*win;
	char	**map;
	void	*img[8];
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
int		get_map_info(char *filename, t_mlx *mlx);
int		get_extension(char *filename);
int		get_first_line(char *str);
int		check_compose(t_mlx *mlx);
int		check_map(t_mlx *mlx);
void	stock_map(char *filename, t_mlx *mlx);
void	init_map(char *filename, t_mlx *mlx);
void	init_image(t_mlx *mlx, char **path);
void	free_mlx(t_mlx *mlx, int i);
void	free_map(t_mlx *mlx);
void	reload_map(t_mlx *mlx);
void	destroy_all_images(t_mlx *mlx, int i);
void	create_image(t_mlx *mlx);
void	check_image(t_mlx *mlx);
void	*c_to_img(char c, t_mlx *mlx, int keycode);
void	map_to_image(t_mlx *mlx, int keycode);
void	mlx_win_init(t_mlx *mlx);
void	get_player_position(t_mlx *mlx);
void	get_exit_position(t_mlx *mlx);
void	moove_player(int keycode, t_mlx *mlx);
void	game_events(int keycode, t_mlx *mlx);
void	init_cross(t_mlx *mlx, int x, int y);
void	pathfinding(char *filename, t_mlx *mlx);
int		*colors_values(void);
#endif
