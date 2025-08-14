/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:18:37 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/14 13:38:59 by fyagbasa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_door_frame(t_game *game)
{
	t_door	*door;

	if (!game->door)
		return (NULL);
	door = game->door;
	door->frame_counter++;
	if (door->frame_counter >= 7)
	{
		door->frame_counter = 0;
		door->current_frame++;
		if (door->current_frame >= 7)
			game->door_anim = 42;
	}
	return (game->door_sprite[door->current_frame]);
}

void	load_door_sprites(t_game *game)
{
	int	w;
	int	h;

	if (!game->mlx)
		return ;
	game->door_sprite[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/door/door_1.xpm", &w, &h);
	game->door_sprite[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/door/door_2.xpm", &w, &h);
	game->door_sprite[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/door/door_3.xpm", &w, &h);
	game->door_sprite[3] = mlx_xpm_file_to_image(game->mlx,
			"./textures/door/door_4.xpm", &w, &h);
	game->door_sprite[4] = mlx_xpm_file_to_image(game->mlx,
			"./textures/door/door_5.xpm", &w, &h);
	game->door_sprite[5] = mlx_xpm_file_to_image(game->mlx,
			"./textures/door/door_6.xpm", &w, &h);
	game->door_sprite[6] = mlx_xpm_file_to_image(game->mlx,
			"./textures/door/door_7.xpm", &w, &h);
}
