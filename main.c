/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:34:37 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/10 15:34:37 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freerealmap(t_map *map)
{
	int	a;

	a = 0;
	while (map->realmap[a])
	{
		free(map->realmap[a]);
		a++;
	}
	free(map->realmap);
}

int main(int argc, char **argv)
{
	t_map	*map;
	if (argc != 2)
		return (0);
	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	map->mapname = ft_strdup(argv[1]);
	if (!map->mapname)
	{
		free(map);
		return (1);
	}
	get_real_map(map);
	for (int i = 0; i < get_line_size(map); i++)
	{
		ft_printf("column: %s\n", map->realmap[i]);
	}
	free(map->mapname);
	freerealmap(map);
	free(map);
    return (0);
}