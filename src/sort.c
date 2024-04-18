/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:04:27 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/18 18:27:54 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushing_to_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	media;

	stack_size = get_stack_size(*stack_a);
	while (stack_size > 3)
	{
		stack_size = get_stack_size(*stack_a);
		media = media_indexes(*stack_a);
		if (stack_size == 3)
			break ;
		if ((*stack_a)->index <= media)
			do_pb(stack_a, stack_b);
		else
			do_ra(stack_a);
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	pushing_to_stack_b(stack_a, stack_b);
	sort_tiny(stack_a);
	while (*stack_b)
	{
		get_position(stack_a);
		get_position(stack_b);
		get_target_position(stack_a, stack_b);
		take_cost(stack_a, stack_b);
		total_cost(stack_a, stack_b);
		find_better_operation(stack_a, stack_b);
	}
	get_position(stack_a);
	printf("STACK A ANTES DE ORDENAR:\n");
	printf_stack(*stack_a);
	if (is_sorted(*stack_a) == 1)
		sorting_stack_a(stack_a);
	// printf("STACK A DEPOIS DE ORDENAR:\n");
	// printf_stack(*stack_a);
}

void	sorting_stack_a(t_stack **stack_a)
{
	int	stack_size;
	int	lower_index;

	stack_size = get_stack_size(*stack_a);
	lower_index = lowest_index(*stack_a);
	if (lower_index > stack_size / 2)
	{
		while (lower_index < stack_size)
		{
			do_ra(stack_a);
			lower_index++;
		}
	}
	else
	{
		while (lower_index > 0)
		{
			do_ra(stack_a);
			lower_index--;
		}
	}
}
