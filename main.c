/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:34:37 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/10 15:34:37 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freerealmap(t_map *map)
{
	int	a;

	a = 0;
	if (!map->realmap)
		return ;
	while (map->realmap[a])
	{
		free(map->realmap[a]);
		a++;
	}
	free(map->realmap);
}

int main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (0);
	game = malloc(sizeof(t_game));
	init_map(game, argv[1]);
	free(game->map->mapname);
	freerealmap(game->map);
	free(game->map);
	free(game);
    return (0);
}