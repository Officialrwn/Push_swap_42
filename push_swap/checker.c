/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/03/15 15:21:11 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialize_struct(t_struct *st, size_t size)
{
	st->op_list = NULL;
	st->a.items = (int *)malloc(sizeof(int) * size);
	st->a.top = -1;
	st->b.items = (int *)malloc(sizeof(int) * size);
	st->b.top = -1;
	ft_memset(st->a.items, 0, size);
	ft_memset(st->b.items, 0, size);
}

static void	validate_argv(t_struct *st, char *argv)
{
	int	num;
	int	i;
	
	num = ft_atoi(argv);
	if (num == 0 && ft_strcmp(argv, "0") != 0)
		print_on_exit(st, ERROR);
 	i = st->a.top;
	while (i >= 0)
	{
		if (num == st->a.items[i--])
			print_on_exit(st, ERROR);
	}
	st->a.items[st->a.top + 1] = num;
	st->a.top++;
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
			if (st->op_list == NULL)
				st->op_list = temp;
			else
				ft_lstaddend(&st->op_list, temp);
			return ;
		}
		i++;
	}
	print_on_exit(st, ERROR);
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
}

int	main(int argc, char **argv)
{
	t_struct	st;
	int			i;
	char		*input;

	if (argc > 1)
	{
		i = argc;
		initialize_struct(&st, argc - 1);
		while (--i > 0)
			validate_argv(&st, argv[i]);
		while (1)
		{
			ft_get_next_line(FD, &input);
			if (ft_strcmp(input, "") == 0)
				break ;
			get_op_calls(&st, input);
			ft_strdel(&input);
		}
		execute_op(&st);
		print_list(&st);
		print_on_exit(&st, VALID);
	}
	return (0);
}
