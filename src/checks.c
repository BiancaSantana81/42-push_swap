/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:19:39 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/08 16:40:05 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_numbers(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (!(str[i] == '+' || str[i] == '-'
				|| (str[i] >= '0' && str[i] <= '9')))
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

	i = 1;
	while (argv[i])
	{
		j = 1;
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
