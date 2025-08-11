/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:09:50 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/11 12:09:50 by fyagbasa         ###   ########.fr       */
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

int	check_wall_ok(t_map *map)
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

int	check_map(t_map *map)
{
	if (get_line_size(map) == -42)
		return (-42);
	if (get_colmn_size(map) < 3 || get_colmn_size(map) == -42)
		return (-42);
	if (check_wall_ok(map) == -42)
		return (-42);
	if (check_chars(map) == -42)
		return (-42);
	if (map->coinc < 1)
		return (-42);
	if (map->playerc != 1)
		return (-42);
	if (map->exitc != 1)
		return (-42);
	if (!check_path(map))
		return (-42);
	ft_printf("Harita doğru!");
	return (1);
}