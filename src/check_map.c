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
	if (get_colmn_size(map) < 3)
		return (-42);
	if (check_wall_ok(map) == -42)
		return (-42);
	if (map->coinc < 1)
		return (-42);
	if (map->playerc != 1)
		return (-42);
	if (map->exitc != 1)
		return (-42);
	ft_printf("Harita doğru!");
	return (1);
}