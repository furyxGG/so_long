/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:43:05 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/11 13:43:05 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_coin_size(t_map *map)
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

void	get_player_size(t_map *map)
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

void	get_exit_size(t_map *map)
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
	get_line_size(game->map);
	get_colmn_size(game->map);
	get_real_map(game->map);
	get_coin_size(game->map);
	get_player_size(game->map);
	get_exit_size(game->map);
	check_map(game->map);
}