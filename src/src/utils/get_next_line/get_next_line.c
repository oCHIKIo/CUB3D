/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:27:57 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/25 12:27:58 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*gnl_check_rem(char **rem)
{
	char	*tmp;
	char	*line;

	if (!gnl_n_pos(*rem))
	{
		if (*rem)
		{
			tmp = gnl_ft_strdup(*rem);
			return (*rem = NULL, line = tmp, line);
		}
		else if (!*rem)
			return (*rem = NULL, NULL);
	}
	else if (gnl_n_pos(*rem))
	{
		line = gnl_ft_substr(*rem, 0, (gnl_n_pos(*rem) - *rem + 1));
		tmp = gnl_ft_strdup(gnl_n_pos(*rem) + 1);
		*rem = NULL;
		*rem = tmp;
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		br;
	static char	*rem;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_malloc((size_t)(BUFFER_SIZE + 1));
	while (!gnl_n_pos(rem))
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br <= 0)
			break ;
		buffer[br] = '\0';
		tmp = gnl_ft_join(rem, buffer);
		rem = tmp;
	}
	buffer = NULL;
	return (gnl_check_rem(&rem));
}
