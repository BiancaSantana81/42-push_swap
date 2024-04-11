/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:04:27 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/11 17:26:23 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	highest_index(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack->next != NULL)
	{
		if (stack->index > stack->next->index)
			index = stack->index;
		stack = stack->next;
	}
	printf ("%d", index);
	return (index);
}

// void	sort_tiny(t_stack *stack)
// {
	
// }
