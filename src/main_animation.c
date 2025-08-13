/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:06:26 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/12 16:06:26 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map->len || 
		new_y < 0 || new_y >= game->map->height)
		return (0);
	if (game->map->realmap[new_y][new_x] == '1')
		return (0);
	if (game->map->realmap[new_y][new_x] == 'C')
		take_coin(game, new_x, new_y);
	if (game->map->realmap[new_y][new_x] == 'E')
		quit_game(game);
	return (1);
}

static void	check_enemy_collision(t_game *game, int x, int y)
{
	if (game->map->realmap[y][x] == 'D')
	{
		ft_printf("Game Over! You touched an enemy!\n");
		freegame(game);
		exit(0);
	}
}

void	helper_anim(t_game *game, int new_x, int new_y)
{
	game->player->pos_x = new_x;
	game->player->pos_y = new_y;
	game->player->step++;
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
}

void	helper_anim2(t_game *game, int n)
{
	if (n == 0)
	{
		player_idle_down(game);
	}
	else if (n == 1)
	{
		player_idle_right(game);
	}
	else if (n == 2)
	{
		player_idle_left(game);
	}
	else if (n == 3)
	{
		player_idle_up(game);
	}
}

void	main_animation(t_game *game, int n)
{
	int	new_x;
	int	new_y;

	new_x = game->player->pos_x;
	new_y = game->player->pos_y;
	if (n == 0)
		new_y++;
	else if (n == 1)
		new_x++;
	else if (n == 2)
		new_x--;
	else if (n == 3)
		new_y--;
	if (!is_valid_move(game, new_x, new_y))
		return ;
	check_enemy_collision(game, new_x, new_y);
	helper_anim2(game, n);
	helper_anim(game, new_x, new_y);
}