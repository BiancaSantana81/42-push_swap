/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:34:53 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/13 21:35:21 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tiny(t_stack **stack)
{
	if ((*stack)->index == highest_index(*stack))
		do_ra(stack);
	else if ((*stack)->next->index == highest_index(*stack))
		do_rra(stack);
	if (is_sorted(*stack) == 1)
		do_sa(stack);
}
