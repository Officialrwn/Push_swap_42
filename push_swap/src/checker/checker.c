/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/10/06 14:47:27 by leo              ###   ########.fr       */
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
	char	**op_list;
	int		i;

	op_list = (char *[]){"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};
	i = 0;
	if (ret)
	{
		while (i < 11)
		{
			if (ft_strcmp(input, op_list[i]) == 0)
				return (store_op_call(&st->stored_op_list, i));
			i++;
		}
		return (store_op_call(&st->stored_op_list, 11));
	}
	return (0);
}

static void	exec_op_in_table(t_struct *st, t_op op, int index, int print_flag)
{
	if (index == 0)
		swap(st, op, print_flag);
	else if (index == 1)
		push(st, op, print_flag);
	else if (index == 2)
		rotate(st, op, print_flag);
	else if (index == 3)
		invalid_op(st, op, print_flag);
}

static void	execute_op(t_struct *st)
{
	t_list	*current_node;
	t_op	op;
	char	*temp;
	int		i;

	current_node = st->stored_op_list;
	while (current_node != NULL)
	{
		op = current_node->content_size;
		temp = (char *)current_node->content;
		i = temp[0] - '0';
		exec_op_in_table(st, op, i, PRINT_OFF);
		current_node = current_node->next;
	}
	print_on_exit(st, VALID, PRINT_ON);
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
		initialize_struct(&st);
		if (argc == 2 && ft_strchr(*argv, ' '))
			argv = init_str_argv(&st, argv, &argc);
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
