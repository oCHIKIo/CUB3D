/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:28:36 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/25 12:28:37 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	index = ft_strlen(s);
	while (index)
	{
		if (s[index] == (char)c)
			return ((char *)s + index);
		index--;
	}
	if (s[0] == (char)c)
		return ((char *)s);
	return (NULL);
}
