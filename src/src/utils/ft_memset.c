/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:28:24 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/25 12:28:25 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	index;

	index = -1;
	while (++index < n)
		((char *)s)[index] = c;
	return (s);
}
