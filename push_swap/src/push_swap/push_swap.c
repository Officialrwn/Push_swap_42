/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/03/19 16:32:46 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	set_pivot(int first, int mid, int last)
{
	int	pivot;

	pivot = mid;
	if (first > pivot && first < last)
		pivot = first;
	else if (last > pivot && last < first)
		pivot = last;
	return (pivot);
}

int	main(int argc, char **argv)
{
	t_struct	st;
	int			count;
	int			pivot;

	if (argc > 1)
	{
		count = argc / 2;
		initialize_struct(&st);
		while (--argc > 0)
			validate_argv(&st, argv[argc]);
		pivot = set_pivot(st.stack_a->num, ft_atoi(argv[count]), st.tail_a->num);
		//print_list(&st);
		ft_printf("%d\n", pivot);
	}
	return (0);
}
