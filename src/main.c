/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:36:19 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/16 10:56:17 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	*stack_b = NULL;
	if (stack_size == 2)
		do_sa(stack_a);
	else if (stack_size == 3)
		sort_tiny(stack_a);
	else if (stack_size > 3)
		sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	// t_stack	*current;

	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (correct_input(argv) == 1)
		ft_putstr_fd("Error\n", 2);
	stack_a = init_stack(argc, argv);
	stack_size = get_stack_size(stack_a);
	assign_indexes(stack_a);
	if (is_sorted(stack_a) == 1)
		push_swap(&stack_a, &stack_b, stack_size);
	return (0);
}
