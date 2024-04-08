/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:40:08 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/08 15:59:21 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Bibliotecas */
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>

/* Estrutura para armazenar dados da stack em lista linkada */
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

/* Estrutura de dados */
void		stack_init(t_stack **stack_a, char **argv);
void		error(t_stack **stack);
void		ft_putstr_fd(char *s, int fd);
void		free_stack(t_stack **stack);
int			only_numbers(char *str);
int			repeats_numbers(char **argv);
int			aux_repeats_numbers(const char *s1, const char *s2);

/*   *** Auxiliares ***  */

/* Usada para pegar os valores tradizos como argumento quando
* eles vem em um único argumento separado por espaços */
char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
long int	ft_atol(const char *nptr);

#endif
