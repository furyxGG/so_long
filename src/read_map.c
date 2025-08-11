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

static void	freeit(char *line, int fd)
{
	free(line);
	while ((line = get_next_line(fd)))
	{
		free(line);
	}
	close(fd);
}

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
	if (a < 3)
		return (-42);
	map->height = a;
	return (a);
}

int	get_colmn_size(t_map *map)
{
	size_t	size;
	int		fd;
	int		a;
	char	*line;
	int		total_lines;

	total_lines = get_line_size(map);
	fd = open(map->mapname, O_RDONLY);
	line = get_next_line(fd);
	size = ft_strlen(line);
	a = 2;
	while (a <= total_lines)
	{
		free(line);
		line = get_next_line(fd);
		if (a == total_lines && size == ft_strlen(line) + 2)
			break;
		if (size != ft_strlen(line))
			return (freeit(line, fd), -42);
		a++;
	}
	freeit(line, fd);
	map->len = size - 2;
	return (size - 2);
}

void	get_real_map(t_map *map)
{
	int		a;
	char	*line;
	int		fd;

	map->realmap = malloc(sizeof(char *) * (get_line_size(map) + 1));
	a = 0;
	fd = open(map->mapname, O_RDONLY);
	while (a < get_line_size(map))
	{
		line = get_next_line(fd);
		map->realmap[a] = ft_strdup(line);
		free(line);
		a++;
	}
	map->realmap[a] = '\0';
	close(fd);
}