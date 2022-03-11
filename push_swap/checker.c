/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/03/12 01:06:53 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
/* 
checker:
The first, named checker which takes integer arguments and reads instructions on
the standard output. Once read, checker executes them and displays OK if integers
are sorted. Otherwise, it will display KO.
*/
void	error_exit(t_struct *st)
{
	free(st->stack_a);
	free(st->stack_b);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_struct st;
	int	i;

	i = 1;
	while (argc >= 2 && i < argc)
	{
		initialize_struct(st, argc);
		if (!ft_isdigit(argv[i]))
			error_exit(&st);
		st.stack_a[i] = ft_atoi(argv[i]);
		i++;
	}
	return (0);
}