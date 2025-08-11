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

void	freerealmap(t_map *map)
{
	int	a;

	a = 0;
	if (!map || !map->realmap)
		return ;
	while (map->realmap[a])
	{
		free(map->realmap[a]);
		a++;
	}
	free(map->realmap);
}

void	freemap(t_game *game)
{
	if (game->map)
	{
		if (game->map->mapname)
			free(game->map->mapname);
		freerealmap(game->map);
		free(game->map);
		game->map = NULL;
	}
}

void	init_game(char *name)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if (!game)
		exit(0);
	init_map(game, name);
	if (!game->map)
	{
		free(game);
		return ;
	}
	init_player(game);
	freemap(game);
	if (game->player)
		free(game->player);
	free(game);
}