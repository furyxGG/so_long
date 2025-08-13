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
	int	a;
	int	b;

	a = 0;
	while (game->map->realmap[a])
	{
		b = 0;
		while (game->map->realmap[a][b])
		{
			if (game->map->realmap[a][b] == 'P')
			{
				game->player->pos_x = b;
				game->player->pos_y = a;
				return ;
			}
			b++;
		}
		a++;
	}
}

int	animation_loop(t_game *game)
{
    static int frame_count = 0;

    if (!game || !game->mlx || !game->win || !game->player)
        return (0);
    frame_count++;
    if (frame_count % 500 == 0)
    {
        mlx_clear_window(game->mlx, game->win);
        draw_map(game);
        if (game->player_f_i[game->current_frame])
        {
            mlx_put_image_to_window(game->mlx, game->win,
                game->player_f_i[game->current_frame],
                game->player->pos_x * 64, game->player->pos_y * 64);
        }

        game->current_frame++;
        if (game->current_frame >= 8)
            game->current_frame = 0;
    }
    return (0);
}

void	init_player(t_game *game)
{
	int	i;

	game->player = malloc(sizeof(t_player));
	if (!game->player)
		return ;
	i = 0;
	while (i < 8)
	{
		game->player_f_i[i] = NULL;
		i++;
	}
	get_player_pos(game);
	game->player->score = 0;
	game->player->step = 0;
	game->current_frame = 0;
}