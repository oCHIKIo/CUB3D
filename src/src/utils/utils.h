/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:29:54 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/25 14:20:30 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "get_next_line/get_next_line.h"
# include "mem_collector/mem_collector.h"
# include <stdlib.h>
# define FAILED 1
# define SUCCESS 0
# define ERROR -1

char	*ft_itoa(int n);
int		ft_isspace(char c);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(const char *s, char c);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
