/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:21:29 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/25 12:21:30 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../raycasting/cub3d.h"
#include "../parser.h"

char	*trim_copy(const char *s)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*out;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (i < len && ft_isspace(s[i]))
		i++;
	if (i == len)
		return (NULL);
	j = len - 1;
	while (j > i && ft_isspace(s[j]))
		j--;
	out = ft_malloc((j - i + 2));
	if (!out)
		return (NULL);
	ft_memcpy(out, s + i, (j - i + 1));
	out[j - i + 1] = '\0';
	return (out);
}

bool	assign_north_texture(t_cub *cub, char **chunks)
{
	if (ft_strcmp(chunks[0], "NO") == 0)
	{
		if (cub->parser.north_texture_path)
			return (FAILED);
		cub->parser.north_texture_path = trim_copy(chunks[1]);
		return (SUCCESS);
	}
	return (FAILED);
}

bool	assign_south_texture(t_cub *cub, char **chunks)
{
	if (ft_strcmp(chunks[0], "SO") == 0)
	{
		if (cub->parser.south_texture_path)
			return (FAILED);
		cub->parser.south_texture_path = trim_copy(chunks[1]);
		return (SUCCESS);
	}
	return (FAILED);
}

bool	assign_west_texture(t_cub *cub, char **chunks)
{
	if (ft_strcmp(chunks[0], "WE") == 0)
	{
		if (cub->parser.west_texture_path)
			return (FAILED);
		cub->parser.west_texture_path = trim_copy(chunks[1]);
		return (SUCCESS);
	}
	return (FAILED);
}

bool	assign_east_texture(t_cub *cub, char **chunks)
{
	if (ft_strcmp(chunks[0], "EA") == 0)
	{
		if (cub->parser.east_texture_path)
			return (FAILED);
		cub->parser.east_texture_path = trim_copy(chunks[1]);
		return (SUCCESS);
	}
	return (FAILED);
}
