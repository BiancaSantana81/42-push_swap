/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:00:29 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/17 14:31:55 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_better_operation(t_stack **stack_b)
{
	t_stack	*current;
	int		lower_cost;

	current = *stack_b;
	lower_cost = find_cheaper(stack_b);
	while (current)
	{
		if (current->total_cost == lower_cost)
		{
			printf("oi, o programa tá pronto pra começar as movimentações\n");
			return ;
		}
		current = current->next;
	}
}
