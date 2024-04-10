/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:40:08 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/10 12:08:45 by bsantana         ###   ########.fr       */
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
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/**** Input validations ****/

/* Checks for non-numeric characters or repeated values. */
int			correct_input(char **argv);

/* - Returns 1 if the string contains any
* character other than a number, space or '+' sign.
* - Returns 1 if the '+' sign is not followed by a number.
* - Returns 0 if the string contains only
* numbers and spaces, including numbers with a '+1' sign.
*/
int			only_numbers(char *str);

/* Checks for repeated values in the input. */
int			repeats_numbers(char **argv);

/* Auxiliary function to check whether the '+' or '-'
* signs should be ignored before comparing the values.
* If +1 and 1 the sign should be disregarded in the comparison.*/
int			aux_repeats_numbers(const char *s1, const char *s2);

/* Checks if the input contains '+0', '-0' or '000'.   
* Return: 
* - Returns 1 if the input contains '+0', '-0' or '000'.
* - Returns 0 otherwise. */
int			zero_count(char *av);

/**** Stack initialization ****/

/*
Initializes a stack with the input values converted to long type.
Checks that the values are within the integer range and adds them to the stack.
*/
t_stack		*init_stack(int ac, char **av);

/*
Creates a new node and initializes its variables.
Return:
 - Pointer to the new node created.
 - NULL in case of memory allocation failure.
*/
t_stack		*add_node(int nbr);

/* Adds the newly created node to the end of the linked list. */
void		node_list_bottom(t_stack **stack, t_stack *new);

/* Returns a pointer to the last node in the list.*/
t_stack		*get_bottom_list(t_stack *stack);

/* Returns the size of the stack. */
int			get_stack_size(t_stack *stack);

/**** Utils for movements ****/

/*
 * Exchanges the values and indices of the first two elements of the stack.
 * 
 * - If the stack is null or has less than two elements,
 * the function does not perform the swap.
 * - The values and indices of the first
 * two elements are swapped with each other.
 */
void		swap(t_stack *stack);

/**** Movements ****/

void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);

/**** Errors and memory deallocation ****/

/* Releases the memory allocated to each node
* in the linked list and the memory space occupied by the list.*/
void		free_stack(t_stack **stack);

/* Outputs an error message to the standard error
* output and frees the memory associated with the linked list.*/
void		error(t_stack **stack);

/**** Utils ****/

long int	ft_atol(const char *nptr);
void		ft_putstr_fd(char *s, int fd);

// # include <stdio.h>
// void		printf_stack(t_stack *stack_a);

#endif
