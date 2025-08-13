/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:17:32 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/13 20:17:32 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	quit_game(t_game *game)
{
	if (game->is_door_open != 0)
	{
		freegame(game);
		exit(0);
	}
}

void	draw_door(t_game *game, int x, int y)
{
	void	*door_frame;

	if (game->door && game->map->exitc > 0)
	{
		if (game->door->pos_x == x && game->door->pos_y == y)
		{
			if (game->player->score == game->map->coinc)
			{
				door_frame = get_door_frame(game);
				if (door_frame)
					mlx_put_image_to_window(game->mlx, game->win, 
				door_frame, x * 64, y * 64);
				game->is_door_open = 42;
			}
			else if (game->player->score == -42)
				mlx_put_image_to_window(game->mlx, game->win, 
				game->door_sprite[6], x * 64, y * 64);
			else
				mlx_put_image_to_window(game->mlx, game->win, 
				game->door_sprite[0], x * 64, y * 64);
		}
	}
}

void	set_door(t_game *game, int x, int y)
{
	game->door->pos_x = x;
	game->door->pos_y = y;
	game->door->current_frame = 0;
	game->door->frame_counter = 10;
}

void	find_door(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	while (game->map->realmap[a])
	{
		b = 0;
		while (game->map->realmap[a][b])
		{
			if (game->map->realmap[a][b] == 'E')
				set_door(game, b, a);
			b++;
		}
		a++;
	}
}

void	init_door(t_game *game)
{
	game->door = malloc(sizeof(t_door) * game->map->exitc);
	find_door(game);
	if (game->map->exitc > 0)
		load_door_sprites(game);
}