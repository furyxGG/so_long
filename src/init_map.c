/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:43:05 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/14 13:45:28 by fyagbasa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_coin_size(t_map *map)
{
	int	a;
	int	b;
	int	size;

	a = 0;
	size = 0;
	while (map->realmap[a])
	{
		b = 0;
		while (map->realmap[a][b])
		{
			if (map->realmap[a][b] == 'C')
				size++;
			b++;
		}
		a++;
	}
	map->coinc = size;
}

static void	get_player_size(t_map *map)
{
	int	a;
	int	b;
	int	size;

	a = 0;
	size = 0;
	while (map->realmap[a])
	{
		b = 0;
		while (map->realmap[a][b])
		{
			if (map->realmap[a][b] == 'P')
				size++;
			b++;
		}
		a++;
	}
	map->playerc = size;
}

static void	get_exit_size(t_map *map)
{
	int	a;
	int	b;
	int	size;

	a = 0;
	size = 0;
	while (map->realmap[a])
	{
		b = 0;
		while (map->realmap[a][b])
		{
			if (map->realmap[a][b] == 'E')
				size++;
			b++;
		}
		a++;
	}
	map->exitc = size;
}

static void	get_enemy_size(t_map *map)
{
	int	a;
	int	b;
	int	size;

	a = 0;
	size = 0;
	while (map->realmap[a])
	{
		b = 0;
		while (map->realmap[a][b])
		{
			if (map->realmap[a][b] == 'D')
				size++;
			b++;
		}
		a++;
	}
	map->enemyc = size;
}

void	init_map(t_game *game, char *filename)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
		return ;
	game->map->mapname = ft_strdup(filename);
	if (!game->map->mapname)
	{
		free(game->map);
		return ;
	}
	game->map->realmap = NULL;
	if (check_map_name(game->map) == -42)
		give_error(game, "Error: Invalid map file name. "
			"It must end with '.ber'.\n");
	if (get_line_size(game->map) == -42)
		give_error(game, "Error: The map must have at least "
			"3 lines and be rectangular.\n");
	if (get_colmn_size(game->map) == -42)
		give_error(game, "Error: The map must have at least "
			"3 columns and be rectangular.\n");
	get_real_map(game->map);
	get_coin_size(game->map);
	get_player_size(game->map);
	get_exit_size(game->map);
	get_enemy_size(game->map);
	check_map(game);
}
