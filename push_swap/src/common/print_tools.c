/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:12:47 by leo               #+#    #+#             */
/*   Updated: 2022/08/21 17:24:32 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_on_exit(t_struct *st, int flag, int print_flag)
{
	if (print_flag)
	{
		if (flag)
			write(2, "Error\n", 6);
		else if (check_if_sorted(st) && !st->stack_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_nodedel(&st->stack_a);
	ft_nodedel(&st->stack_b);
	ft_lstdel(&st->op_list, &ft_del_lst_content);
	exit(flag);
}
