/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/03/13 13:01:29 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialize_struct(t_struct *st, int size)
{
	st->list = NULL;
	st->stack_a = (int *)malloc(sizeof(int) * size);
	st->stack_b = (int *)malloc(sizeof(int) * size);
	ft_memset(st->stack_a, 0, size);
	ft_memset(st->stack_b, 0, size);
}

static int	validate_argv(t_struct *st, char *argv, int cur_index)
{
	int	i;
	int	num;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i++]) == 0)
			error_exit(st, 0);
	}
	num = ft_atoi(argv);
	while (--cur_index >= 0)
	{
		if (st->stack_a[cur_index] == num)
			error_exit(st, 0);
	}
	return (num);
}

static void	get_op_calls(t_struct *st, char *input)
{
	t_list	*temp;
	int		i;
	int		op_len;
	char	num;

	i = 0;
	op_len = sizeof(g_op) / sizeof(g_op[0]);
	while (i < op_len)
	{
		if (ft_strcmp(input, g_op[i]) == 0)
		{
			num = OP_INDEX[i];
			temp = ft_lstnew(&num, 1);
			temp->content_size = (size_t)i;
			if (st->list == NULL)
				st->list = temp;
			else
				ft_lstaddend(&st->list, temp);
			return ;
		}
		i++;
	}
	error_exit(st, 0);
}

static void	execute_op(t_struct *st)
{
	t_list	*current_node;
	t_op	op;
	char	*temp;
	int		i;

	current_node = st->list;
	while (current_node != NULL)
	{
		op = current_node->content_size;
		temp = (char *)current_node->content;
		i = temp[0] - '0';
		g_execute_op[i](st, op);
		current_node = current_node->next;
	}
}

int	main(int argc, char **argv)
{
	t_struct	st;
	int			i;
	char		*input;

	i = 0;
	if (argc > 1)
	{
		initialize_struct(&st, argc - 1);
		while (i++ < argc - 1)
			st.stack_a[i - 1] = validate_argv(&st, argv[i], i - 1);
		while (1)
		{
			ft_get_next_line(FD, &input);
			if (ft_strcmp(input, "") == 0)
				break ;
			get_op_calls(&st, input);
			ft_strdel(&input);
		}
		execute_op(&st);
		free_heap(&st);
	}
	return (0);
}
