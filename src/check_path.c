/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:38:27 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/11 14:38:27 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_player_position(t_map *map, int *x, int *y)
{
	int	a;
	int	b;

	a = 0;
	while (map->realmap[a])
	{
		b = 0;
		while (map->realmap[a][b])
		{
			if (map->realmap[a][b] == 'P')
			{
				*x = b;
				*y = a;
				return ;
			}
			b++;
		}
		a++;
	}
}

static char	**create_map_copy(t_map *map)
{
	char	**tmp;
	int		a;

	tmp = malloc(sizeof(char *) * (map->height + 1));
	if (!tmp)
		return (NULL);
	a = 0;
	while (a < map->height)
	{
		tmp[a] = ft_strdup(map->realmap[a]);
		if (!tmp[a])
		{
			while (--a >= 0)
				free(tmp[a]);
			free(tmp);
			return (NULL);
		}
		a++;
	}
	tmp[a] = NULL;
	return (tmp);
}

static void	free_map_copy(char **copy, int height)
{
	int	a;

	a = 0;
	while (a < height)
	{
		free(copy[a]);
		a++;
	}
	free(copy);
}

static void	flood_fill(char **copy, int height, int len, t_map *map)
{
	if (height < 0 || height >= map->height || len < 0 || len >= map->len)
        return ;
	if (ft_strchr("1XD", copy[height][len]))
		return ;
	copy[height][len] = 'X';
	flood_fill(copy, height + 1, len, map);
	flood_fill(copy, height - 1, len, map);
	flood_fill(copy, height, len + 1, map);
	flood_fill(copy, height, len - 1, map);
}

int	check_path(t_map *map)
{
	char	**tmp;
	int		x;
	int		y;

	get_player_position(map, &x, &y);
	tmp = create_map_copy(map);
	flood_fill(tmp, y, x, map);
	x = 0;
	y = 1;
	while (tmp[x])
	{
		if (!validate_chars(tmp[x], "1XD0"))
		{
			y = 0;
			break ;
		}
		x++;
	}
	free_map_copy(tmp, map->height);
	return(y);
}