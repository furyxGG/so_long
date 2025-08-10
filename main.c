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
	ft_printf("column: %d", get_colmn_size(map));
	free(map->mapname);
	free(map);
    return (0);
}