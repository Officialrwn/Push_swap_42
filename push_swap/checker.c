/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/03/12 21:03:44 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_heap(t_struct *st)
{
	free(st->stack_a);
	free(st->stack_b);
	ft_lstdel(&st->list, &ft_bzero);
}

void	print_list(t_list *list)
{
	t_list *current_node;

	current_node = list;
	printf("test");
	while (current_node != NULL)
	{
		//printf("%zu\n", current_node->content_size);
		current_node = current_node->next;
	}
}

void	error_exit(t_struct *st, int flag)
{
	free_heap(st);
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
	t_stack	*temp;
	int		i;
	int		op_len;
	size_t	num;

	i = 0;
	op_len = sizeof(g_op) / sizeof(g_op[0]);
	while (i < op_len)
	{
		if (ft_strcmp(input, g_op[i]) == 0)
		{
			num = OP_INDEX[i] - '0';
		 	if (st->list == NULL)
				st->list = temp;
			else
			{
				temp = ft_lstnew(NULL, 0);
				temp->content_size = num;
				ft_lstaddend(&st->list, temp);
			}
		// MAKE T_STACK LIKE LINEKD LIST
 		return ;
		}
		i++;
	}
	//error_exit(st, 0);
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
		if (ft_strcmp(input, "Exit") == 0)
			break ;
		get_op_calls(&st, input);
	}
	//print_list(st.list);
	free_heap(&st);
	return (0);
}
