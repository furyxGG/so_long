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

void	free_animations(t_game *game)
{
	int	a;

	a = 0;
	if (game->wall)
	{
		while (a < 9)
		{
			if (game->wall->wallimage[a])
				mlx_destroy_image(game->mlx, game->wall->wallimage[a]);
			a++;
		}
		free(game->wall);
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
	int	i;

	if (!game)
		return ;
	i = 0;
	while (i < 8)
	{
		if (game->player_f_i[i])
			mlx_destroy_image(game->mlx, game->player_f_i[i]);
		i++;
	}
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
	free(game);
}

void	init_game(char *name)
{
	t_game *game;

	(void)name;

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
	ft_printf("player init\n");
	init_mlx(game);
	freegame(game);
}