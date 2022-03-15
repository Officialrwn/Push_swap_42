/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/03/15 21:44:39 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialize_struct(t_struct *st)
{
	st->op_list = NULL;
	st->stack_a = NULL;
	st->stack_b = NULL;
}

static void	validate_argv(t_struct *st, char *argv)
{
	t_list	*current_node;
	t_list	*temp;
	size_t	len;
	int		num;

	current_node = st->stack_a;
	num = ft_atoi(argv);
	if (num == 0 && ft_strcmp(argv, "0") != 0)
		print_on_exit(st, ERROR);
	while (current_node != NULL)
	{
		if (ft_strcmp(current_node->content, argv) == 0)
			print_on_exit(st, ERROR);
		current_node = current_node->next;
	}
	len = ft_strlen(argv) + 1;
	temp = ft_lstnew(argv, len);
	if (st->stack_a == NULL)
		st->stack_a = temp;
	else
		ft_lstaddend(&st->stack_a, temp);
}
//cpytostackb(st, argv, len);

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

	i = 0;
	if (argc > 1)
	{
		initialize_struct(&st);
		while (i++ < argc - 1)
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
		print_list(st.stack_a, st.stack_b);
		print_on_exit(&st, VALID);
	}
	return (0);
}
