/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:19:39 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/09 13:46:43 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '+' || str[i] == '-'
				|| (str[i] >= '0' && str[i] <= '9')
				|| str[i] == 32))
			return (1);
		if ((str[i] == '-' || str[i] == '+')
			&& (!(str[i + 1] >= '0' && str[i + 1] <= '9')))
			return (1);
		i++;
	}
	return (0);
}

int	repeats_numbers(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (j != i && aux_repeats_numbers(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	aux_repeats_numbers(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

int	zero_count(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '+' || av[i] == '-')
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	correct_input(char **argv)
{
	int			i;
	int			nb_zeros;

	i = 1;
	nb_zeros = 0;
	while (argv[i])
	{
		if (only_numbers(argv[i]) == 1)
			return (1);
		if (repeats_numbers(&argv[i]) == 1)
			return (1);
		nb_zeros += zero_count(argv[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (1);
	return (0);
}
