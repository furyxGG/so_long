/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fyagbasa <fyagbasa@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 01:55:51 by fyagbasa          #+#    #+#             */
/*   Updated: 2025/08/14 13:53:30 by fyagbasa         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	take_key(int keycode, void *param)
{
	if (keycode == 53 || keycode == 65307)
	{
		freegame(param);
		exit(0);
	}
	if (keycode == 100)
		main_animation(param, 1);
	if (keycode == 115)
		main_animation(param, 0);
	if (keycode == 97)
		main_animation(param, 2);
	if (keycode == 119)
		main_animation(param, 3);
	return (0);
}

int	take_close(void *param)
{
	freegame(param);
	exit(0);
	return (0);
}
