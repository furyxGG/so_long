/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:35:33 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/14 13:59:15 by fyagbasa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct s_map
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

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
	int	step;
	int	score;
	int	direct;
	int	img_x;
	int	img_y;
}				t_player;

typedef struct s_enemy
{
	int				pos_x;
	int				pos_y;
	int				img_x;
	int				img_y;
	int				current_frame;
	int				frame_counter;
}				t_enemy;

typedef struct s_door
{
	int				pos_x;
	int				pos_y;
	int				img_x;
	int				img_y;
	int				current_frame;
	int				frame_counter;
}				t_door;

typedef struct s_coin
{
	int				pos_x;
	int				pos_y;
	int				img_x;
	int				img_y;
	int				current_frame;
	int				frame_counter;
}				t_coin;

typedef struct s_wall
{
	void	*wallimage[9];
	int		x;
	int		y;
}				t_wall;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_player	*player;
	t_enemy		*enemies;
	t_coin		*coins;
	t_wall		*wall;
	t_door		*door;
	int			is_door_open;
	int			door_anim;
	void		*enemy_sprite[4];
	void		*door_sprite[7];
	void		*coin_sprite[4];
	void		*player_f_i[8];
	int			current_frame;
	int			current_enemy;
}				t_game;

int		get_line_size(t_game *game);
int		get_colmn_size(t_game *game);
void	get_real_map(t_game *game);

void	check_map(t_game *game);
int		check_path(t_map *map);
int		check_map_name(t_map *map);

void	init_map(t_game *game, char *filename);
void	init_game(char *name);
void	init_player(t_game *game);

int		validate_chars(char *line, char *chars);

void	freegame(t_game *game);

void	init_mlx(t_game *game);
void	init_wall(t_game *game);
void	init_enemy(t_game *game);
void	init_coin(t_game *game);
void	init_door(t_game *game);

int		take_key(int keycode, void *param);
int		take_close(void *param);
void	take_coin(t_game *game, int new_x, int new_y);

void	draw_map(t_game *game);
void	draw_enemy(t_game *game, int x, int y);
void	draw_coin(t_game *game, int x, int y);
void	draw_door(t_game *game, int x, int y);
void	draw_score_steps(t_game *game);
int		animation_loop(t_game *game);
void	player_idle_down(t_game *game);
void	player_idle_right(t_game *game);
void	player_idle_left(t_game *game);
void	player_idle_up(t_game *game);
void	main_animation(t_game *game, int n);

void	*get_enemy_frame(t_game *game, int enemy_index);
void	load_enemy_sprites(t_game *game);

void	*get_coin_frame(t_game *game, int enemy_index);
void	load_coin_sprites(t_game *game);

void	*get_door_frame(t_game *game);
void	load_door_sprites(t_game *game);

void	give_error(t_game *game, char *msg);
void	quit_game(t_game *game);

#endif
