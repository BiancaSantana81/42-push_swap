/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:04:27 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/11 18:25:50 by bsantana         ###   ########.fr       */
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

void	sort_tiny(t_stack *stack)
{
	if (stack->index == highest_index(stack))
		do_ra(&stack);
	else if (stack->next->index == highest_index(stack))
		do_rra(&stack);
	if (is_sorted(stack) == 1)
		do_sa(&stack);
}
