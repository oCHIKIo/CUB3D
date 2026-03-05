/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_collector.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddou <mhaddou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:28:13 by mhaddou           #+#    #+#             */
/*   Updated: 2025/11/26 10:22:48 by mhaddou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_COLLECTOR_H
# define MEM_COLLECTOR_H

# include "../utils.h"
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_mem_chunk
{
	void				*ptr;
	struct s_mem_chunk	*next;
}						t_mem_chunk;

void					ft_free(bool exit_val);
void					*ft_malloc(size_t size);

#endif
