/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:27:25 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/25 13:27:26 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../mem_collector/mem_collector.h"
# include <stdlib.h>
# include <unistd.h>

char	*gnl_n_pos(char *str);
char	*get_next_line(int fd);
ssize_t	gnl_ft_strlen(const char *str);
char	*gnl_ft_strdup(const char *str);
char	*gnl_ft_join(char *s1, char *s2);
char	*gnl_ft_substr(const char *str, ssize_t start, ssize_t max);

#endif
