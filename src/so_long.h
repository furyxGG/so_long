/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:35:33 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/10 15:35:33 by fyagbasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_map
{
	char	**realmap;
	char	*mapname;
	int		playerc;
	int		coinc;
	int		enemyc;
	int		len;
	int		height;
	int		is_rect;
	int		is_wall_ok;
	int		is_path_ok;
}				t_map;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
}				t_game;

int	get_line_size();

#endif