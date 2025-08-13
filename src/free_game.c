/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:25:33 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/13 23:25:33 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_animations(t_game *game)
{
	int	a;

	if (!game)
		return;
		
	a = 0;
	if (game->wall)
	{
		while (a < 9)
		{
			if (game->wall->wallimage[a] && game->mlx)
				mlx_destroy_image(game->mlx, game->wall->wallimage[a]);
			a++;
		}
		free(game->wall);
	}
	a = 0;
	while (a < 8)
	{
		if (game->player_f_i[a] && game->mlx)
			mlx_destroy_image(game->mlx, game->player_f_i[a]);
		a++;
	}
	a = -1;
	while (++a < 4)
	{
		if (game->enemy_sprite[a] && game->mlx)
			mlx_destroy_image(game->mlx, game->enemy_sprite[a]);
	}
	a = -1;
	while (++a < 4)
	{
		if (game->coin_sprite[a] && game->mlx)
			mlx_destroy_image(game->mlx, game->coin_sprite[a]);
	}
	a = -1;
	while (++a < 7)
	{
		if (game->door_sprite[a] && game->mlx)
			mlx_destroy_image(game->mlx, game->door_sprite[a]);
	}
}

void	freemap(t_game *game)
{
	int	a;

	a = 0;
	if (game->map)
	{
		if (game->map->mapname)
			free(game->map->mapname);
		if (game->map->realmap)
		{
			while (game->map->realmap[a])
			{
				free(game->map->realmap[a]);
				a++;
			}
		}
		free(game->map->realmap);
		free(game->map);
		game->map = NULL;
	}
}

void	freegame(t_game *game)
{
	if (!game)
		return ;
	free_animations(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	freemap(game);
	if (game->player)
		free(game->player);
	if (game->enemies)
		free(game->enemies);
	if (game->coins)
		free(game->coins);
	if (game->door)
		free(game->door);
	free(game);
}
