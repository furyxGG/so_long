/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:45:42 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/11 14:45:42 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->realmap[i])
	{
		j = 0;
		while (game->map->realmap[i][j])
		{
			if (game->map->realmap[i][j] == 'P')
			{
				game->player->pos_x = j;
				game->player->pos_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		return ;
	get_player_pos(game);
	game->player->score = 0;
	game->player->step = 0;
}