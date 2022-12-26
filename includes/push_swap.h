/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:46:25 by hel-kame          #+#    #+#             */
/*   Updated: 2022/12/23 18:52:39 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		sa(int *a);
int		pa(int *a, int *b);
void	ra(int *a);
void	rra(int *a);
int		sb(int *b);
int		pb(int *a, int *b);
void	rb(int *b);
void	rrb(int *b);
void	print_piles(int *a, int *b); //PRINTER HAVE TO DELETE
#endif
