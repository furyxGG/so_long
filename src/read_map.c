/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:29:04 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/10 17:29:04 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_line_size(t_map *map)
{
	int		a;
	int		fd;
	char	*line;

	a = 0;
	fd = open(map->mapname, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		a++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (a);
}