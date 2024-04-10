/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:58:51 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/10 15:40:32 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;
	long	nbr;

	stack_a = NULL;
	i = 1;
	while (i < ac)
	{
		nbr = ft_atol(av[i]);
		if (!(nbr > INT_MIN && nbr < INT_MAX))
			error(&stack_a);
		if (i == 1)
			stack_a = add_node((int)nbr);
		else
			node_list_bottom(&stack_a, add_node((int)nbr));
		i++;
	}
	return (stack_a);
}
