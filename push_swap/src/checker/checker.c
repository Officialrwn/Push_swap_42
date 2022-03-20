/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/03/20 14:05:20 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static uint16_t	convert_to_bits(int i)
{
	uint16_t	bit;

	bit = 0 ^ 1 << i;
	return (bit);
}

static int	get_op_calls(t_struct *st, char *input)
{
	int		i;
	int		flag;
	int		op_len;

	i = 0;
	flag = 0;
	op_len = sizeof(g_op) / sizeof(g_op[0]);
	while (i < op_len)
	{
		if (ft_strcmp(input, g_op[i]) == 0)
		{
			flag = ((convert_to_bits(i) & STACK_AB) != 0);
			i = i - 2 * (flag);
			return (store_op_call(&st->op_list, i, flag));
		}
		i++;
	}
	print_on_exit(st, ERROR);
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct	st;
	int			fd;
	int			ret;
	char		*input;

	fd = 0;
	ret = 1;
	input = NULL;
	if (argc > 1)
	{
		initialize_struct(&st);
		while (--argc > 0)
			validate_argv(&st, argv[argc]);
		while (ret)
		{
			ret = ft_get_next_line(fd, &input);
			if (ret == 1)
				get_op_calls(&st, input);
			ft_strdel(&input);
		}
		execute_op(&st);
	}
	//needs max int check.
	return (0);
}
