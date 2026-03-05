/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:20:43 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/25 12:20:46 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../raycasting/cub3d.h"
#include "../parser.h"

int	create_rgb(unsigned char r, unsigned char g, unsigned char b)
{
	return ((r << 16) | (g << 8) | b);
}

bool	is_valid_rgb_value(char *rgb_str)
{
	int	i;
	int	value;

	i = 0;
	value = 0;
	while (rgb_str[i])
	{
		if (rgb_str[i] < '0' || rgb_str[i] > '9')
			return (false);
		value = value * 10 + (rgb_str[i] - '0');
		if (value > 255)
			return (false);
		i++;
	}
	return (true);
}
