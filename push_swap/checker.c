/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/03/16 23:31:08 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	store_op_call(t_list **op_list, int op_enum, int flag)
{
	t_list	*temp;
	char	op_i;

	op_i = OP_INDEX[op_enum];
	temp = ft_lstnew(&op_i, 1);
	temp->content_size = (size_t)op_enum;
	if ((*op_list) == NULL)
		(*op_list) = temp;
	else
		ft_lstadd(op_list, temp);
	if (flag)
		return (store_op_call(op_list, op_enum - 1, 0));
	return (1);
}

static int	get_op_calls(t_struct *st, char *input)
{
	int		i;
	int		flag;
	int		op_len;

	i = 0;
	op_len = sizeof(g_op) / sizeof(g_op[0]);
	while (i < op_len)
	{
		if (ft_strcmp(input, g_op[i]) == 0)
		{
			flag = ((convert_to_bits(i) & STACK_AB) != 0);
			return (store_op_call(&st->op_list, i, flag));
		}
		i++;
	}
	print_on_exit(st, ERROR);
	return (0);
}

static void	execute_op(t_struct *st)
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
	//printf("tail a: %s\n", (char *)st->tail_a->content);
	print_on_exit(st, VALID);
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
	return (0);
}
