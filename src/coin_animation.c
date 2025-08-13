/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:53:28 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/13 18:53:28 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_coin_frame(t_game *game, int coin_index)
{
	t_coin *coin;

	if (!game->coins || coin_index >= game->map->coinc)
		return NULL;
	coin = &game->coins[coin_index];
	coin->frame_counter++;
	if (coin->frame_counter >= 4)
	{
		coin->frame_counter = 0;
		coin->current_frame++;
		if (coin->current_frame >= 4)
			coin->current_frame = 0;
	}
	return (game->coin_sprite[coin->current_frame]);
}

void	load_coin_sprites(t_game *game)
{
	int w;
	int	h;

	if (!game->mlx)
		return;
	game->coin_sprite[0] = mlx_xpm_file_to_image(game->mlx, 
		"./textures/coin/coin0.xpm", &w, &h);
	game->coin_sprite[1] = mlx_xpm_file_to_image(game->mlx, 
		"./textures/coin/coin1.xpm", &w, &h);
	game->coin_sprite[2] = mlx_xpm_file_to_image(game->mlx, 
		"./textures/coin/coin2.xpm", &w, &h);
	game->coin_sprite[3] = mlx_xpm_file_to_image(game->mlx, 
		"./textures/coin/coin3.xpm", &w, &h);
}