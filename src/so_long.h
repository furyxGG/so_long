/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:35:33 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/10 15:35:33 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>

#define MLX_KEY_PRESS       2
#define MLX_DESTROY_NOTIFY 17

typedef struct	s_map
{
	char	**realmap;
	char	*mapname;
	int		playerc;
	int		coinc;
	int		enemyc;
	int		exitc;
	int		len;
	int		height;
}				t_map;

typedef struct	s_player
{
	int	pos_x;
	int	pos_y;
	int	step;
	int	score;
	int	direct;
	int	img_x;
	int	img_y;
}				t_player;

typedef struct	s_wall
{
	void	*wallimage[9];
	int		x;
	int		y;
}				t_wall;


typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	*player;
	t_wall		*wall;
	void		*player_f_i[8];
    int			current_frame;
}				t_game;

int		get_line_size(t_map *map);
int		get_colmn_size(t_map *map);
void	get_real_map(t_map *map);
void	get_coin_size(t_map *map);
void	get_player_size(t_map *map);
void	get_exit_size(t_map *map);
void	get_enemy_size(t_map *map);
void	get_player_pos(t_game *game);

int		check_wall_ok(t_map *map);
int		check_map(t_map *map);
int		check_path(t_map *map);

void	init_map(t_game *game, char *filename);
void	init_game(char *name);
void	init_player(t_game *game);

int		validate_chars(char *line, char *chars);

void	freemap(t_game *game);
void	freegame(t_game *game);

void	init_mlx(t_game *game);

void	init_wall(t_game *game);

int		take_key(int keycode, void *param);
int		take_close(void *param);

void	draw_map(t_game *game);
void	animate_player(t_game *game, char **paths);
int		animation_loop(t_game *game);
void	player_idle_down(t_game *game);
void	player_idle_right(t_game *game);
void	player_idle_left(t_game *game);
void	player_idle_up(t_game *game);
void	main_animation(t_game *game, int n);


#endif