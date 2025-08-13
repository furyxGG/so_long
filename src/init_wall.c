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

static int	get_wall_type(t_game *game, int x, int y)
{
	if (y == 0 && x != 0 && x != game->map->len - 1)
		return (0);
	else if (y == game->map->height - 1 && x != 0 && x != game->map->len - 1)
		return (1);
	else if (y == 0 && x == 0)
		return (2);
	else if (y == 0 && x == game->map->len - 1)
		return (3);
	else if (y == game->map->height - 1 && x == 0)
		return (4);
	else if (y == game->map->height - 1 && x == game->map->len - 1)
		return (5);
	else if (x == 0)
		return (6);
	else if (x == game->map->len - 1)
		return (7);
	else if (game->map->realmap[y][x] == '1')
		return (8);
	return (-1);
}

static void	draw_wall_at_position(t_game *game, int x, int y)
{
	int	wall_type;

	wall_type = get_wall_type(game, x, y);
	if (wall_type != -1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall->wallimage[wall_type], x * 64, y * 64);
}

void	draw_map(t_game *game)
{
	int 	x;
	int 	y;
    char    *step;

	y = 0;
	while (game->map->realmap[y])
	{
		x = 0;
		while (game->map->realmap[y][x])
		{
			if (game->map->realmap[y][x] == 'D')
				draw_enemy(game, x, y);
			// if (game->map->realmap[y][x] == 'C')
			draw_wall_at_position(game, x, y);
			x++;
		}
		y++;
	}
    step = ft_itoa(game->player->step);
    mlx_string_put(game->mlx, game->win, 32, game->map->height * 64 - 32, 0x497367, step);
    free(step);
}

static void	load_wall_images(t_game *game)
{
	char	*paths[9];
	int		i;

	paths[0] = "./textures/wall/wall_up.xpm";
	paths[1] = "./textures/wall/wall_down.xpm";
	paths[2] = "./textures/wall/wall_up_l.xpm";
	paths[3] = "./textures/wall/wall_up_r.xpm";
	paths[4] = "./textures/wall/wall_down_l.xpm";
	paths[5] = "./textures/wall/wall_down_r.xpm";
	paths[6] = "./textures/wall/wall_left.xpm";
	paths[7] = "./textures/wall/wall_right.xpm";
	paths[8] = "./textures/wall/wall.xpm";
	i = 0;
	while (i < 9)
	{
		game->wall->wallimage[i] = mlx_xpm_file_to_image(game->mlx,
			paths[i], &game->wall->x, &game->wall->y);
		i++;
	}
}

void	init_wall(t_game *game)
{
	game->wall = malloc(sizeof(t_wall));
	if (!game->wall)
		return ;
	load_wall_images(game);
	draw_map(game);
}