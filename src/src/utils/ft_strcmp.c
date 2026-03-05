/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:28:32 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/25 12:28:33 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	index;

	index = 0;
	while ((s1[index] != '\0') && (s1[index] == s2[index]))
		index++;
	if (s1[index] == s2[index])
		return (0);
	else
		return (s1[index] - s2[index]);
}
