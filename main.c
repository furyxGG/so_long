/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:27:58 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/14 13:29:52 by fyagbasa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == '\0')
	{
		ft_putstr_fd("Error! Usage: ./so_long map.ber\n", 2);
		return (0);
	}
	init_game(argv[1]);
	return (0);
}
