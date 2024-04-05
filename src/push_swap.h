/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:40:08 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/05 17:33:48 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Bibliotecas */
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

/* Estrutura para armazenar dados da stack em lista linkada */
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

/* Estrutura de dados */
void		stack_init(char **argv);

/*   *** Auxiliares ***  */

/* Usada para pegar os valores tradizos como argumento quando
* eles vem em um único argumento separado por espaços */
char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t n);
long int	ft_atoi(const char *nptr);

#endif
