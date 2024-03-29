/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:12:47 by leo               #+#    #+#             */
/*   Updated: 2022/10/06 14:51:03 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_on_exit(t_struct *st, int is_error, int print_flag)
{
	if (print_flag)
	{
		if (is_error)
			write(2, "Error\n", 6);
		else if (check_if_sorted(st) && !st->stack_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
	{
		ft_nodedel(&st->lis_arr.head);
		free(st->lis_arr.lis);
		free(st->lis_arr.num);
		st->lis_arr.lis = NULL;
		st->lis_arr.num = NULL;
	}
	if (st->argc > 0)
		free_argv(st->argv, st->argc);
	ft_nodedel(&st->stack_a);
	ft_nodedel(&st->stack_b);
	ft_lstdel(&st->stored_op_list, &ft_del_lst_content);
	exit(is_error);
}

void	free_argv(char **argv, int argc)
{
	while (argc--)
	{
		ft_strdel(&argv[argc]);
	}
	free(argv);
	argv = NULL;
}
