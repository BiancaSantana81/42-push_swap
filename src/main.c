/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:36:19 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/11 15:37:46 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (correct_input(argv) == 1)
		ft_putstr_fd("Error\n", 2);
	stack_a = init_stack(argc, argv);
	stack_size = get_stack_size(stack_a);
	assign_indexes(stack_a);
	printf_stack(stack_a);
	return (0);
}
