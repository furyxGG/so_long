/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 01:07:54 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/12 01:07:54 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void draw_map(t_game *game)
{
    int a;
	int	b;

	a = 0;
    while (game->map->realmap[a])
    {
        b = 0;
        while (game->map->realmap[a][b])
        {
            if (game->map->realmap[a][b] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall->wallimage, b * 64, a * 64);
            b++;
        }
        a++;
    }
}
void	init_wall(t_game *game)
{
	game->wall = malloc(sizeof(t_wall));
	if (!game->wall)
		return ;
	game->wall->wallimage = mlx_xpm_file_to_image(game->mlx, "./textures/wall/wall.xpm", &game->wall->x, &game->wall->y);
	draw_map(game);
	mlx_loop(game->mlx);
}