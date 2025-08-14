/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:09:50 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/14 13:35:34 by fyagbasa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_chars(char *line, char *chars)
{
	int	a;

	a = 0;
	while (line[a])
	{
		if (!ft_strchr(chars, line[a]))
			return (0);
		a++;
	}
	return (1);
}

static int	check_chars(t_map *map)
{
	int	a;

	a = 0;
	while (map->realmap[a])
	{
		if (!validate_chars(map->realmap[a], "01PCDE"))
			return (-42);
		a++;
	}
	return (1);
}

static int	check_wall_ok(t_map *map)
{
	int	a;
	int	b;
	int	len;

	a = 0;
	len = map->len - 1;
	while (map->realmap[a])
	{
		if (map->realmap[a][0] != '1' || map->realmap[a][len] != '1')
			return (-42);
		if (a == 0 || a == map->height - 1)
		{
			b = 0;
			while (b <= len)
			{
				if (map->realmap[a][b] != '1')
					return (-42);
				b++;
			}
		}
		a++;
	}
	return (1);
}

int	check_map_name(t_map *map)
{
	char	**arr;
	int		a;

	arr = ft_split(map->mapname, '.');
	a = 0;
	while (arr[a])
		a++;
	if (arr[a - 1][0] != 'b' || arr[a - 1][1] != 'e'
		|| arr[a - 1][2] != 'r' || arr[a - 1][3] != '\0')
	{
		a = -1;
		while (arr[++a])
			free(arr[a]);
		free(arr);
		return (-42);
	}
	a = -1;
	while (arr[++a])
		free(arr[a]);
	free(arr);
	return (1);
}

void	check_map(t_game *game)
{
	if (get_line_size(game->map) == -42)
		give_error(game, "Error: The map must have at least 3 lines.\n");
	if (get_colmn_size(game->map) < 3 || get_colmn_size(game->map) == -42)
		give_error(game, "Error: The map must have at least 3 columns.\n");
	if (check_wall_ok(game->map) == -42)
		give_error(game, "Error: The map must be surrounded by walls.\n");
	if (check_chars(game->map) == -42)
		give_error(game, "Error: The map contains invalid characters.\n");
	if (game->map->playerc != 1)
		give_error(game, "Error: The map must contain exactly one player.\n");
	if (game->map->coinc < 1)
		give_error(game, "Error: The map must contain at least one coin.\n");
	if (game->map->exitc != 1)
		give_error(game, "Error: The map must contain exactly one exit.\n");
	if (!check_path(game->map))
		give_error(game, "Error: There is no valid path to collect all "
			"coins and reach the exit.\n");
}
