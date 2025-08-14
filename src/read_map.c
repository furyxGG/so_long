/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:29:04 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/14 13:58:01 by fyagbasa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	freeit(char *line, int fd)
{
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
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
	if (fd < 0)
		ft_printf("Error: There is no map file.\n");
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

static int	clean_line(char *line)
{
	int	size;

	size = ft_strlen(line);
	if (size > 0 && line[size - 1] == '\n')
		size--;
	if (size > 0 && line[size - 1] == '\r')
		size--;
	return (size);
}

int	get_colmn_size(t_map *map)
{
	int		fd;
	int		a;
	char	*line;
	int		size;

	fd = open(map->mapname, O_RDONLY);
	if (fd < 0)
		ft_printf("Error: There is no map file.\n");
	line = get_next_line(fd);
	size = clean_line(line);
	a = 2;
	while (a <= get_line_size(map))
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		if (size != clean_line(line))
			return (freeit(line, fd), -42);
		a++;
	}
	freeit(line, fd);
	map->len = size;
	return (size);
}

void	get_real_map(t_map *map)
{
	int		a;
	char	*line;
	int		fd;

	if (get_line_size(map) > 0)
		map->realmap = malloc(sizeof(char *) * (get_line_size(map) + 1));
	if (!map->realmap)
		return ;
	a = 0;
	fd = open(map->mapname, O_RDONLY);
	while (a < get_line_size(map))
	{
		line = get_next_line(fd);
		map->realmap[a] = ft_strtrim(line, "\r\n");
		free(line);
		a++;
	}
	map->realmap[a] = '\0';
	close(fd);
}
