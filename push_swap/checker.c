/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/03/16 19:51:24 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	store_op_call(t_list **op_list, int op_enum)
{
	t_list	*temp;
	char	op_i;

	op_i = OP_INDEX[op_enum];
	temp = ft_lstnew(&op_i, 1);
	temp->content_size = (size_t)op_enum;
	if ((*op_list) == NULL)
		(*op_list) = temp;
	else
		ft_lstaddend(op_list, temp);
}

static int	get_op_calls(t_struct *st, char *input)
{
	int		i;
	int		op_len;

	i = 0;
	op_len = sizeof(g_op) / sizeof(g_op[0]);
	while (i < op_len)
	{
		if (ft_strcmp(input, g_op[i]) == 0)
		{
			//i = uintflag. if flag == SS, RR, RRR
			//put into its own function
			store_op_call(&st->op_list, i);
			return (0);
		}
		i++;
	}
	return (print_on_exit(st, ERROR));
}

static int	execute_op(t_struct *st)
{
	t_list	*current_node;
	t_op	op;
	char	*temp;
	int		i;

	current_node = st->op_list;
	while (current_node != NULL)
	{
		op = current_node->content_size;
		temp = (char *)current_node->content;
		i = temp[0] - '0';
		g_execute_op[i](st, op);
		current_node = current_node->next;
	}
	print_list(st->stack_a, st->stack_b);
	printf("tail a: %s\n", (char *)st->tail_a->content);
	return (print_on_exit(st, VALID));
}

int	main(int argc, char **argv)
{
	t_struct	st;
	int			i;
	int			fd;
	char		*input;

	i = 0;
	fd = 0;
	if (argc > 1)
	{
		initialize_struct(&st);
		while (i++ < argc - 1)
			validate_argv(&st, argv[i]);
		while (1)
		{
			ft_get_next_line(fd, &input);
			if (ft_strcmp(input, "") == 0)
				break ;
			if (get_op_calls(&st, input) == 1)
				return (1);
			ft_strdel(&input);
		}
		return (execute_op(&st));
	}
	return (0);
}
