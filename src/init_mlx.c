/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:57:41 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/11 16:57:41 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->len * 64, game->map->height * 64, "so_long");
	init_wall(game);
	init_enemy(game);
	init_coin(game);
	init_door(game);
	player_idle_down(game);
	mlx_hook(game->win, 2, 1L<<0, take_key, game);
	mlx_hook(game->win, 17, 1L<<17, take_close, game);
	mlx_loop(game->mlx);
}