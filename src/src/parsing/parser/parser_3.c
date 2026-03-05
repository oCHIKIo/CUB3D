/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:21:23 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/26 09:02:40 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../raycasting/cub3d.h"
#include "../parser.h"

static int	count_non_empty(char **chunks)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (chunks[i])
	{
		if (chunks[i][0] != '\0')
			count++;
		i++;
	}
	return (count);
}

static void	rebuild_token(char **chunks, char **compact)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (chunks[i] && chunks[i][0] == '\0')
		i++;
	if (chunks[i])
		compact[j++] = chunks[i++];
	while (chunks[i] && chunks[i][0] == '\0')
		i++;
	if (chunks[i])
	{
		compact[j] = chunks[i++];
		while (chunks[i])
		{
			if (chunks[i][0] != '\0')
				compact[j] = join_with_space(compact[j], chunks[i]);
			i++;
		}
		j++;
	}
	compact[j] = NULL;
}

char	**normalize_tokens(char **chunks)
{
	char	**compact;
	int		count;

	count = count_non_empty(chunks);
	if (count < 2)
		return (chunks);
	compact = ft_malloc(sizeof(char *) * 3);
	rebuild_token(chunks, compact);
	return (compact);
}

bool	read_file_lines(t_cub *cub)
{
	t_load_map	*load_map;
	int			len;

	load_map = &cub->parser.load_map;
	load_map->line = get_next_line(load_map->fd);
	if (!load_map->line)
		return (FAILED);
	load_map->index = 0;
	while (load_map->line)
	{
		len = ft_strlen(load_map->line);
		if (len > 0 && load_map->line[len - 1] == '\n')
			load_map->line[len - 1] = '\0';
		cub->parser.map_file_lines[load_map->index++] = load_map->line;
		load_map->line = get_next_line(load_map->fd);
	}
	cub->parser.map_file_lines[load_map->index] = NULL;
	load_map->index = 0;
	return (SUCCESS);
}
