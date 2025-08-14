/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:39:36 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/14 13:40:58 by fyagbasa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	take_coin(t_game *game, int new_x, int new_y)
{
	game->map->realmap[new_y][new_x] = 'Q';
	game->player->score++;
	ft_printf("Coin collected! %d coin left.\n",
		game->map->coinc - game->player->score);
}

void	draw_coin(t_game *game, int x, int y)
{
	void	*coin_frame;
	int		c;

	if (game->coins && game->map->coinc > 0)
	{
		c = 0;
		while (c < game->map->coinc)
		{
			if (game->coins[c].pos_x == x && game->coins[c].pos_y == y)
			{
				coin_frame = get_coin_frame(game, c);
				if (coin_frame)
					mlx_put_image_to_window(game->mlx, game->win,
						coin_frame, x * 64, y * 64);
				break ;
			}
			c++;
		}
	}
}

static void	set_coin(t_game *game, int x, int y, int size)
{
	game->coins[size].pos_x = x;
	game->coins[size].pos_y = y;
	game->coins[size].current_frame = 0;
	game->coins[size].frame_counter = size * 10;
}

static void	find_all_coins(t_game *game)
{
	int	a;
	int	b;
	int	size;

	if (game->map->coinc > 0)
	{
		a = 0;
		size = 0;
		while (game->map->realmap[a])
		{
			b = 0;
			while (game->map->realmap[a][b])
			{
				if (game->map->realmap[a][b] == 'C')
				{
					set_coin(game, b, a, size);
					size++;
				}
				b++;
			}
			a++;
		}
	}
}

void	init_coin(t_game *game)
{
	game->coins = malloc(sizeof(t_coin) * game->map->coinc);
	find_all_coins(game);
	if (game->map->coinc > 0)
		load_coin_sprites(game);
}
