/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:57:41 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/14 13:47:23 by fyagbasa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_score_steps(t_game *game)
{
	char	*step;
	char	*score;

	step = ft_itoa(game->player->step);
	score = ft_itoa(game->player->score);
	score = ft_strjoin("Score: ", score);
	mlx_string_put(game->mlx, game->win, 32,
		game->map->height * 64 - 32, 0x497367, step);
	mlx_string_put(game->mlx, game->win,
		game->map->len * 64 / 2, 20, 0x497367, score);
	free(score);
	free(step);
}

void	init_mlx(t_game *game)
{
	int	w;
	int	h;

	game->mlx = mlx_init();
	mlx_get_screen_size(game->mlx, &w, &h);
	if (game->map->height * 64 > h || game->map->len * 64 > w)
		give_error(game, "Error: Your screen is not enought.\n");
	game->win = mlx_new_window(game->mlx, game->map->len * 64,
			game->map->height * 64, "so_long");
	init_wall(game);
	init_enemy(game);
	init_coin(game);
	init_door(game);
	player_idle_down(game);
	mlx_hook(game->win, 2, 1L << 0, take_key, game);
	mlx_hook(game->win, 17, 1L << 17, take_close, game);
	mlx_loop(game->mlx);
}
