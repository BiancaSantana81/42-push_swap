/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:55:20 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/16 14:35:26 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_b = *stack_b;
	while (current_b)
	{
		current_a = *stack_a;
		current_b->target_pos = INT_MAX;
		while (current_a)
		{
			if (current_b->index < current_a->index
				&& current_a->index < current_b->target_pos)
			{
				current_b->target_pos = current_a->index;
			}
			current_a = current_a->next;
		}
		current_b = current_b->next;
	}
}
