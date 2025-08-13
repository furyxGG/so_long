/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:50:47 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/13 17:50:47 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_enemy_frame(t_game *game, int enemy_index)
{
	t_enemy *enemy;

	if (!game->enemies || enemy_index >= game->map->enemyc)
		return NULL;
	enemy = &game->enemies[enemy_index];
	enemy->frame_counter++;
	if (enemy->frame_counter >= 5)
	{
		enemy->frame_counter = 0;
		enemy->current_frame++;
		if (enemy->current_frame >= 4)
			enemy->current_frame = 0;
	}
	
	return (game->enemy_sprite[enemy->current_frame]);
}

void	load_enemy_sprites(t_game *game)
{
	int w;
	int	h;

	if (!game->mlx)
		return;
	game->enemy_sprite[0] = mlx_xpm_file_to_image(game->mlx, 
		"./textures/enemy/demon_0.xpm", &w, &h);
	game->enemy_sprite[1] = mlx_xpm_file_to_image(game->mlx, 
		"./textures/enemy/demon_1.xpm", &w, &h);
	game->enemy_sprite[2] = mlx_xpm_file_to_image(game->mlx, 
		"./textures/enemy/demon_2.xpm", &w, &h);
	game->enemy_sprite[3] = mlx_xpm_file_to_image(game->mlx, 
		"./textures/enemy/demon_3.xpm", &w, &h);
}