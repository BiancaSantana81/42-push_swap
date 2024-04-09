/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:40:08 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/09 16:45:19 by bsantana         ###   ########.fr       */
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
int			correct_input(char **argv);
void		error(t_stack **stack);
void		ft_putstr_fd(char *s, int fd);
void		free_stack(t_stack **stack);
int			only_numbers(char *str);
int			repeats_numbers(char **argv);
int			aux_repeats_numbers(const char *s1, const char *s2);
int			zero_count(char *av);
t_stack		*init_stack(int ac, char **av);
void		node_list_bottom(t_stack **stack, t_stack *new);
t_stack		*get_bottom_list(t_stack *stack);
t_stack		*add_node(int nbr);

/*   *** Auxiliares ***  */

/* Usada para pegar os valores tradizos como argumento quando
* eles vem em um único argumento separado por espaços */
long int	ft_atol(const char *nptr);
void		printf_stack(t_stack *stack_a);

#endif
