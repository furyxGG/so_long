/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:54:00 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/14 13:55:37 by fyagbasa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	animate_player(t_game *game, char **paths)
{
	int	a;

	a = 0;
	while (a < 8)
	{
		if (game->player_f_i[a])
			mlx_destroy_image(game->mlx, game->player_f_i[a]);
		a++;
	}
	a = 0;
	while (a < 8)
	{
		game->player_f_i[a] = mlx_xpm_file_to_image(game->mlx, paths[a],
				&game->player->img_x, &game->player->img_y);
		a++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player_f_i[0],
		game->player->pos_x * 64, game->player->pos_y * 64);
	mlx_loop_hook(game->mlx, animation_loop, game);
}

void	player_idle_down(t_game *game)
{
	char	*paths[8];

	paths[0] = "./textures/character/idle/down_0.xpm";
	paths[1] = "./textures/character/idle/down_1.xpm";
	paths[2] = "./textures/character/idle/down_2.xpm";
	paths[3] = "./textures/character/idle/down_3.xpm";
	paths[4] = "./textures/character/idle/down_4.xpm";
	paths[5] = "./textures/character/idle/down_5.xpm";
	paths[6] = "./textures/character/idle/down_6.xpm";
	paths[7] = "./textures/character/idle/down_7.xpm";
	animate_player(game, paths);
}

void	player_idle_right(t_game *game)
{
	char	*paths[8];

	paths[0] = "./textures/character/idle/right_0.xpm";
	paths[1] = "./textures/character/idle/right_1.xpm";
	paths[2] = "./textures/character/idle/right_2.xpm";
	paths[3] = "./textures/character/idle/right_3.xpm";
	paths[4] = "./textures/character/idle/right_4.xpm";
	paths[5] = "./textures/character/idle/right_5.xpm";
	paths[6] = "./textures/character/idle/right_6.xpm";
	paths[7] = "./textures/character/idle/right_7.xpm";
	animate_player(game, paths);
}

void	player_idle_left(t_game *game)
{
	char	*paths[8];

	paths[0] = "./textures/character/idle/left_0.xpm";
	paths[1] = "./textures/character/idle/left_1.xpm";
	paths[2] = "./textures/character/idle/left_2.xpm";
	paths[3] = "./textures/character/idle/left_3.xpm";
	paths[4] = "./textures/character/idle/left_4.xpm";
	paths[5] = "./textures/character/idle/left_5.xpm";
	paths[6] = "./textures/character/idle/left_6.xpm";
	paths[7] = "./textures/character/idle/left_7.xpm";
	animate_player(game, paths);
}

void	player_idle_up(t_game *game)
{
	char	*paths[8];

	paths[0] = "./textures/character/idle/up_0.xpm";
	paths[1] = "./textures/character/idle/up_1.xpm";
	paths[2] = "./textures/character/idle/up_2.xpm";
	paths[3] = "./textures/character/idle/up_3.xpm";
	paths[4] = "./textures/character/idle/up_4.xpm";
	paths[5] = "./textures/character/idle/up_5.xpm";
	paths[6] = "./textures/character/idle/up_6.xpm";
	paths[7] = "./textures/character/idle/up_7.xpm";
	animate_player(game, paths);
}
