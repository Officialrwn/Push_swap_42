/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/03/21 09:41:34 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	initialize_intarrays(int **lis, int **num, int size)
{
	(*lis) = (int *)malloc(sizeof(int) * size);
	(*num) = (int *)malloc(sizeof(int) * size);
	if (!(*num) || !(*lis))
		exit (1);
	while (size--)
		(*lis)[size] = 1;
}

int	main(int argc, char **argv)
{
	t_struct	st;
	int			*lis;
	int			*num;
	int			size;

	if (argc > 1)
	{
		size = argc - 1;
		initialize_struct(&st);
		initialize_intarrays(&lis, &num, size);
		while (--argc > 0)
			num[argc - 1] = validate_argv(&st, argv[argc]);
		int test = get_lisindex(&lis, num, size);
		print_intarr(lis, size);
		print_list(&st);
	}
	return (0);
}
