/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:04:27 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/11 18:08:47 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack->next != NULL)
	{
		if (index < stack->index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

// void	sort_tiny(t_stack *stack)
// {
// }
