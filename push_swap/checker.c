/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/03/12 17:19:54 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_struct *st, int flag)
{
	free(st->stack_a);
	free(st->stack_b);
	if (!flag)
		write(2, "Error\n", 6);
	else
		write(1, "KO\n", 3);
	exit(1);
}

int	validate_argv(t_struct *st, char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i++]) == 0)
			error_exit(st, 0);
	}
	return (ft_atoi(argv));
}

void	get_op_calls(t_struct *st, char *input)
{
	st->flag = 0;
	input = NULL;
	// loop through g_op find match and then match that index
	// with OP_INDEX and store it in a linked list..
}

int	main(int argc, char **argv)
{
	t_struct	st;
	int			i;
	int			num;
	char		*input;

	i = 0;
	if (argc == 1)
		return (0);
	initialize_struct(&st, argc - 1);
	while (i++ < argc - 1)
	{
		num = validate_argv(&st, argv[i]);
		if (ft_memchr(st.stack_a, num, argc - 1) != NULL)
			error_exit(&st, 0);
		st.stack_a[i - 1] = num;
	}
	while (1)
	{
		i = 0;
		ft_get_next_line(STDIN, &input);
		get_op_calls(&st, input);
	}
	return (0);
}
