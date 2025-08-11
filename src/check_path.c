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
	int	i;
	int	j;

	i = 0;
	while (map->realmap[i])
	{
		j = 0;
		while (map->realmap[i][j])
		{
			if (map->realmap[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static char	**create_map_copy(t_map *map)
{
	char	**tmp;
	int		i;

	tmp = malloc(sizeof(char *) * (map->height + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		tmp[i] = ft_strdup(map->realmap[i]);
		if (!tmp[i])
		{
			while (--i >= 0)
				free(tmp[i]);
			free(tmp);
			return (NULL);
		}
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

static void	free_map_copy(char **copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(copy[i]);
		i++;
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