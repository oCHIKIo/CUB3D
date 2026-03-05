/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:21:57 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/25 12:21:58 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"
#include "parser.h"

bool	is_empty_string(char *str)
{
	if (!str)
		return (true);
	while (*str)
	{
		if (!ft_isspace(*str))
			return (false);
		str++;
	}
	return (true);
}

void	skip_empty_lines(t_cub *cub)
{
	char	**lines;

	lines = cub->parser.map_file_lines;
	while (lines[cub->parser.load_map.index]
		&& is_empty_string(lines[cub->parser.load_map.index]))
		cub->parser.load_map.index++;
}
