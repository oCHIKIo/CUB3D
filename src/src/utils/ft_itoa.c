/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:28:19 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/25 12:28:20 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static long	count(long rep)
{
	long	total;

	total = 0;
	if (rep <= 0)
		total++;
	while (rep)
	{
		rep = rep / 10;
		total++;
	}
	return (total);
}

char	*ft_itoa(int n)
{
	int		counter;
	char	*str;
	long	rep;

	rep = n;
	counter = count(rep);
	str = (char *)ft_malloc(counter + 1);
	if (rep < 0)
	{
		str[0] = '-';
		rep *= -1;
	}
	str[counter] = '\0';
	counter -= 1;
	if (rep == 0)
		return (*str = '0', str);
	while (rep != 0)
	{
		str[counter] = '0' + (rep % 10);
		rep /= 10;
		counter--;
	}
	return (str);
}
