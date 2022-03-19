/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/03/20 01:20:00 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_intarr(int *num, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_printf("%d ", num[i++]);
	ft_putstr("\n");
}

void	get_lis(int lis[], t_struct st, int size)
{
	int		num[size];
 	int		i;

	i = 0;
	while (st.stack_a)
	{
		lis[i] = 1;
		num[i++] = st.stack_a->num;
		st.stack_a = st.stack_a->next;
	}
	print_intarr(num, size);
}

int	main(int argc, char **argv)
{
	t_struct	st;
	int			lis[argc - 1];
	int			size;

	if (argc > 1)
	{
		size = argc - 1;
		initialize_struct(&st);
		while (--argc > 0)
			validate_argv(&st, argv[argc]);
		get_lis(lis, st, size);

		print_intarr(lis, size);
		print_list(&st);
	}
	return (0);
}
