/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:49:11 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/11 14:49:11 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	give_error(t_game *game, char *msg)
{
	ft_printf("%s", msg);
	freegame(game);
    exit(0);
}

static void	helper_game(t_game *game)
{
	int a;

	game->is_door_open = 0;
	game->door = NULL;
	game->enemies = NULL;
	game->coins = NULL;
	game->map = NULL;
	game->player = NULL;
	game->wall = NULL;
	game->mlx = NULL;
	game->win = NULL;
	a = -1;
	while (++a < 8)
		game->player_f_i[a] = NULL;
	a = -1;
	while (++a < 4)
		game->enemy_sprite[a] = NULL;
	a = -1;
	while (++a < 4)
		game->coin_sprite[a] = NULL;
	a = -1;
	while (++a < 7)
		game->door_sprite[a] = NULL;
}

void	init_game(char *name)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit(0);
	helper_game(game);
	init_map(game, name);
	if (!game->map)
	{
		freegame(game);
		return ;
	}
	init_player(game);
	init_mlx(game);
}