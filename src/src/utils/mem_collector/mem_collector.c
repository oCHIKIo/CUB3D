/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_collector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:28:08 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/26 10:22:43 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem_collector.h"

static t_mem_chunk	**get_mem_list(void)
{
	static t_mem_chunk	*mem_list;

	return (&mem_list);
}

void	*ft_malloc(size_t size)
{
	void		*ptr;
	t_mem_chunk	*new_node;

	ptr = malloc(size);
	if (!ptr)
		return (ft_free(FAILED), NULL);
	new_node = malloc(sizeof(t_mem_chunk));
	if (!new_node)
		return (ft_free(FAILED), NULL);
	new_node->ptr = ptr;
	new_node->next = *get_mem_list();
	*get_mem_list() = new_node;
	return (ptr);
}

void	ft_free(bool exit_val)
{
	t_mem_chunk	*tmp;
	t_mem_chunk	*current;

	current = *get_mem_list();
	while (current)
	{
		tmp = current->next;
		if (current->ptr)
			free(current->ptr);
		free(current);
		current = tmp;
	}
	*get_mem_list() = NULL;
	if (exit_val)
		exit(1);
}
