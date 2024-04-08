/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:09:04 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/08 16:36:40 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atol(const char *nptr)
{
	int			i;
	long		r;
	int			sign;

	i = 0;
	r = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
	{
		i++;
	}
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 + (nptr[i] - '0');
		i++;
	}
	return (r * sign);
}

void	stack_init(t_stack **stack_a, char **argv)
{
	long		nbr;
	int			i;

	i = 1;
	while (argv[i])
	{
		if (only_numbers(argv[i]) == 1)
			ft_putstr_fd("Error\n", 2);
		nbr = ft_atol(argv[i]);
		if (!(nbr >= INT_MIN && nbr <= INT_MAX))
			error(stack_a);
		i++;
	}
	if (repeats_numbers(argv) == 1)
		error(stack_a);
}
