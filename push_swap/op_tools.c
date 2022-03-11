/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:49:48 by leo               #+#    #+#             */
/*   Updated: 2022/03/12 00:22:28 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


void	swap_ab(t_struct *st)
{
	//	sa - 	swap the first 2 elements at the top of stack a. 
	//	(Do nothing if there is only one or no elements).

	//	sb - 	swap the first 2 elements at the top of stack b. 
	//	(Do nothing if there is only one or no elements).

	//	ss -	sa + sb
}

void	push_ab(t_struct *st)
{
	//	take the first element at the top of b and put it at the top of a. 
	//	Do nothing if b is empty.

	//	take the first element at the top of a and put it at the top of b. 
	//	Do nothing if b is empty.
}

void	rotate_ab(t_struct *st)
{
	// 	ra - shift up all elements of stack a by 1. 
	//	The first element becomes the last one.

	// 	rb - shift up all elements of stack a by 1. 
	//	The first element becomes the last one.

	//	rr -	ra + rb
}

void	reverse_rotate_ab(t_struct *st)
{
	// 	rra - shift down all elements of stack a by 1. 
	//	The last element becomes the first one.

	// 	rrb - shift down all elements of stack a by 1. 
	//	The last element becomes the first one.

	//	rrr -	rra + rrb