/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:21:20 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/25 12:21:20 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../raycasting/cub3d.h"
#include "../parser.h"

char	*join_with_space(char *s1, char *s2)
{
	t_jwithspace	x;

	x.len1 = ft_strlen(s1);
	x.len2 = ft_strlen(s2);
	x.result = ft_malloc(x.len1 + x.len2 + 2);
	if (!x.result)
		return (NULL);
	x.i = 0;
	while (x.i < x.len1)
	{
		x.result[x.i] = s1[x.i];
		x.i++;
	}
	x.result[x.i] = ' ';
	x.i++;
	x.j = 0;
	while (x.j < x.len2)
	{
		x.result[x.i] = s2[x.j];
		x.i++;
		x.j++;
	}
	x.result[x.i] = '\0';
	return (x.result);
}

bool	check_file_extension(char *file_path, char *ext)
{
	char	*dot;

	dot = ft_strrchr(file_path, '.');
	if (!dot || ft_strcmp(dot, ext))
		return (false);
	return (true);
}

int	map_line_count(t_cub *cub)
{
	int		fd;
	char	*line;
	int		index;

	index = 0;
	fd = open(cub->parser.map_file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Unable to open map file\n", 2);
		return (ERROR);
	}
	line = get_next_line(fd);
	while (line)
	{
		index++;
		line = get_next_line(fd);
	}
	close(fd);
	return (index);
}

bool	assign_textures_and_colors(t_cub *cub, char **chunks)
{
	if (assign_texture(cub, chunks) == SUCCESS)
		return (true);
	if (assign_colors(cub, chunks) == SUCCESS)
		return (true);
	ft_putstr_fd("Error: Invalid texture or color format\n", 2);
	return (false);
}
