/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:36:19 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/09 10:27:51 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	// int		stack_size;

	stack_a = NULL;
	stack_b = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (correct_input(argv) == 1)
		ft_putstr_fd("Error\n", 2);
}
