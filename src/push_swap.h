/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:40:08 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/09 18:05:08 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/**** Libraries ****/

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

/* Stack used for sorting */
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

/**** Input validations ****/

/**/
int			correct_input(char **argv);

/**/
int			only_numbers(char *str);

/**/
int			repeats_numbers(char **argv);

/**/
int			aux_repeats_numbers(const char *s1, const char *s2);

/**/
int			zero_count(char *av);

/**** Stack initialization ****/

/**/
t_stack		*init_stack(int ac, char **av);

/**/
void		node_list_bottom(t_stack **stack, t_stack *new);

/**/
t_stack		*get_bottom_list(t_stack *stack);

/**/
t_stack		*add_node(int nbr);

/**** Errors and memory deallocation ****/

/**/
void		free_stack(t_stack **stack);

/**/
void		error(t_stack **stack);

/**** Auxiliares ****/

long int	ft_atol(const char *nptr);
void		ft_putstr_fd(char *s, int fd);

//void		printf_stack(t_stack *stack_a);

#endif
