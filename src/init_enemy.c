/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:18:37 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/14 13:43:28 by fyagbasa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_enemy(t_game *game, int x, int y)
{
	void	*enemy_frame;
	int		c;

	if (game->enemies && game->map->enemyc > 0)
	{
		c = 0;
		while (c < game->map->enemyc)
		{
			if (game->enemies[c].pos_x == x && game->enemies[c].pos_y == y)
			{
				enemy_frame = get_enemy_frame(game, c);
				if (enemy_frame)
					mlx_put_image_to_window(game->mlx, game->win,
						enemy_frame, x * 64, y * 64);
				break ;
			}
			c++;
		}
	}
}

static void	set_enemy(t_game *game, int x, int y, int size)
{
	game->enemies[size].pos_x = x;
	game->enemies[size].pos_y = y;
	game->enemies[size].current_frame = 0;
	game->enemies[size].frame_counter = size * size;
}

static void	find_all_enemies(t_game *game)
{
	int	a;
	int	b;
	int	size;

	if (game->map->enemyc > 0)
	{
		a = 0;
		size = 0;
		while (game->map->realmap[a])
		{
			b = 0;
			while (game->map->realmap[a][b])
			{
				if (game->map->realmap[a][b] == 'D')
				{
					set_enemy(game, b, a, size);
					size++;
				}
				b++;
			}
			a++;
		}
	}
}

void	init_enemy(t_game *game)
{
	game->enemies = malloc(sizeof(t_enemy) * game->map->enemyc);
	find_all_enemies(game);
	if (game->map->enemyc > 0)
		load_enemy_sprites(game);
}
