/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/08/02 02:10:27 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	store_op_call(t_list **op_list, int op_enum)
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
	return (1);
}

static int	get_op_calls(t_struct *st, char *input, int ret)
{
	int		i;
	int		op_len;

	i = 0;
	op_len = sizeof(g_op) / sizeof(g_op[0]);
	if (ret)
	{
		while (i < op_len)
		{
			if (ft_strcmp(input, g_op[i]) == 0)
				return (store_op_call(&st->op_list, i));
			i++;
		}
		print_on_exit(st, ERROR);
	}
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
		argv++;
		if (argc == 2)
			argv = init_str_argv(argv[0], &argc);
		initialize_struct(&st);
		while (--argc)
			validate_argv(&st, *(argv++));
		while (ret)
		{
			ret = ft_get_next_line(fd, &input);
			get_op_calls(&st, input, ret);
			ft_strdel(&input);
		}
		execute_op(&st);
	}
	return (0);
}
