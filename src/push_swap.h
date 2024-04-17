/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:40:08 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/17 14:20:47 by bsantana         ###   ########.fr       */
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
	int				total_cost;
	struct s_stack	*next;
}	t_stack;

/**** Input validations ****/

/* Checks for non-numeric characters or repeated values. */
int			correct_input(char **argv);

/* 
 * - Returns 1 if the string contains any
 * character other than a number, space or '+' sign.
 * - Returns 1 if the '+' sign is not followed by a number.
 * - Returns 0 if the string contains only
 * numbers and spaces, including numbers with a '+1' sign.
 */
int			only_numbers(char *str);

/* Checks for repeated values in the input. */
int			repeats_numbers(char **argv);

/* 
 * Auxiliary function to check whether the '+' or '-'
 * signs should be ignored before comparing the values.
 * If +1 and 1 the sign should be disregarded in the comparison.
 */
int			aux_repeats_numbers(const char *s1, const char *s2);

/* 
 * Checks if the input contains '+0', '-0' or '000'.   
 * Return: 
 * - Returns 1 if the input contains '+0', '-0' or '000'.
 * - Returns 0 otherwise. 
 */
int			zero_count(char *av);

/**** Stack initialization ****/

/*
 * Initializes a stack with the input values converted to long type.
 * Checks that the values are within the
 * integer range and adds them to the stack.
 */
t_stack		*init_stack(int ac, char **av);

/*
 * Creates a new node and initializes its variables.
 * Return:
 * - Pointer to the new node created.
 * - NULL in case of memory allocation failure.
 */
t_stack		*add_node(int nbr);

/* Adds the newly created node to the end of the linked list. */
void		node_list_bottom(t_stack **stack, t_stack *new);

/* Returns a pointer to the last node in the list.*/
t_stack		*get_bottom_list(t_stack *stack);

/* 
 * Returns a pointer to the penultimate node on the stack.
 * If the stack is empty or has only one node, returns NULL.
 */
t_stack		*get_before_bottom_list(t_stack *stack);

/* Returns the size of the stack. */
int			get_stack_size(t_stack *stack);

/**** Sorting  ****/

/* 
 * Checks if the stack is sorted.
 *  - Returns 1 if not sorted.
 *   - Returns 0 if sorted. 
 */
int			is_sorted(t_stack *stack);

/*
 * Assigns an index to each of the values on the stack.
 * As an example:
 *               0    9    1
 *              [1]  [3]  [2]
 * 
 * By assigning indices we can compare the
 * values of the indices instead of the actual value. 
*/
void		assign_indexes(t_stack *stack_a);

/*
 * It analyzes which sorting method is
 * the most valid according to the size of the stack.
 * - = 2 -> swap the two elements.
 * - = 3 -> tiny sort.
 * - > 3 -> sort. 
 */
void		push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);

/*
 * Sorts a stack of three elements.
 * 
 * - If the first element in the stack has the
 * highest index, it performs a rotation (ra).
 * - If the second element in the stack has
 * the highest index, it performs an inverse rotation (rra).
 * - Checks if the list is sorted and, if not, swaps the first two elements. 
 */
void		sort_tiny(t_stack **stack);

/*FUNÇÃO PRINCIPAL DO ALGORITMO - EDITAR COMENTÁRIO*/
void		sort(t_stack **stack_a, t_stack **stack_b);

/* Search for the index with the highest value. */
int			highest_index(t_stack *stack);

/*
 * This function transfers the smallest values from stack A
 * to stack B, keeping only the three largest values in A.
 */
void		pushing_to_stack_b(t_stack **stack_a, t_stack **stack_b);

/* 
 * Take the average of the stack indices.
 *
 * To do this, we add up all the
 * indices and divide them by the size of the stack. 
 * Example:
 * - Indices: [1] [2] [3] [4] [5] [6] = 21
 * - Stack size: 6
 * - Result = 21 / 6 = 3.5 
 */
int			media_indexes(t_stack *stack);

/* Function to find the position of the value in the list.
 *
 * Initializes the list and increments
 * stack->pos according to its position on the stack. 
 */
void		get_position(t_stack **stack);


/*
 * Determine the subsequent position in which the
 * element of stack B should be in relation to stack A.
 * 
 * For example, consider a stack with the following values:
 * 
 *     A      B
 * 	   35     5  -- target_pos [35]
 *     50    25  -- target_pos [35]
 *     55    10  -- target_pos [35]
 *           40  -- target_pos [50]
 * 
 * To do this, I scroll through the elements of A in relation
 *  to B, as long as I don't find a higher value in B and as 
 * long as I don't find a higher value in A than the last 
 * value updated in target_pos. 
 * 
 * Otherwise, I update target_pos to this new value. 
 */
void		get_target_position(t_stack **stack_a, t_stack **stack_b);

/**** functions for calculating costs ****/

/*
 * Calculates the cost of bringing
 * a value from the stack to the top.
 * If the value is in the second half of the stack,
 *  it is considered negative. Example:
 *  5   20   37  41
 * [0] [1] [-2] [-1]
 */
void		take_cost(t_stack **stack_a, t_stack **stack_b);

void		calculate_cost_a(t_stack *stack_a);
void		calculate_cost_b(t_stack *stack_b);


/*
 * Add up the costs of A and B to find the cheapest movement price.
 * To do this, it checks what it costs to bring the target_position
 *  of B to the top of the stack and
 *  what it costs to bring element B to the top of B.
 * 
 *  As an example:
 * 
 * 1   8 - target_pos [10] - cost a = 1 - cost b = 0 - total cost = 1
 * 10  3 - target_pos [10] - cost a = 1 - cost b = 1 - total cost = 2
 * 11  7 - target_pos [10] - cost a = 1 - cost b = 2 - total cost = 3
 * 
 */
void		total_cost(t_stack **stack_a, t_stack **stack_b);


/* Returns the cheapest total cost. */
int			find_cheaper(t_stack **stack_b);

/*FUNÇÃO PARA ENCONTRAR A MELHOR OPERAÇÃO A SER FEITA - COM MENOS CUSTOS - TESTES E COMENTÁRIO*/
void		find_better_operation(t_stack **stack_b);

/**** Utils for movements ****/

/*
 * Exchanges the values and indices of the first two elements of the stack.
 * 
 * - If the stack is null or has less than two elements,
 * the function does not perform the swap.
 * - The values and indices of the first
 * two elements are swapped with each other.
 */
void		swap(t_stack **stack);

/* 
 * Pushes the first element from one stack to another.
 * If the source stack is empty, it does not perform any operation.
 */
void		push(t_stack **src, t_stack **dest);

/*  
 * Moves the first element of the stack to the end,
 *  reorganizing the elements of the stack. 
 */
void		rotate(t_stack **stack);

/* 
 * Moves the last element of the stack to the beginning,
 *  reorganizing the elements of the stack.
 */
void		rev_rotate(t_stack **stack);

/**** Movements ****/

void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);

/**** Errors and memory deallocation ****/

/* 
 * Releases the memory allocated to each node
 * in the linked list and the memory space occupied by the list.
 */
void		free_stack(t_stack **stack);

/* 
 * Outputs an error message to the standard error
 * output and frees the memory associated with the linked list.
 */
void		error(t_stack **stack);

/**** Utils ****/

long int	ft_atol(const char *nptr);
void		ft_putstr_fd(char *s, int fd);


/* This function calculates the sum of two positive values
 * or their absolute values, if any of the input values 
 * values is negative. This ensures that the resulting sum
 * is always correct, even if the input values are negative.
 */
int			sum_cost(int a, int b);

/*EXCLUIR AO FINAL DO PROJETO*/
# include <stdio.h>
void		printf_stack(t_stack *stack);

#endif
