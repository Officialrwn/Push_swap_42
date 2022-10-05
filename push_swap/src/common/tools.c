/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:49:08 by leo               #+#    #+#             */
/*   Updated: 2022/10/06 00:21:31 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	initialize_struct(t_struct *st)
{
	st->op_list = NULL;
	st->stack_a = NULL;
	st->stack_b = NULL;
	st->tail_a = NULL;
	st->tail_b = NULL;
	st->argv = NULL;
	st->argc = 0;
	st->min = 0;
	st->max = 0;
}

int	validate_argv(t_struct *st, char *argv)
{
	t_node	*current_node;
	t_node	*temp;
	long	num;

	current_node = st->stack_a;
	num = ft_atol(argv);
	if (num > MAXINT || num < MININT || (num == 0 && !ft_strequ(argv, "0")
			&& !ft_strequ(argv, "-0") && !ft_strequ(argv, "+0")))
		print_on_exit(st, ERROR, PRINT_ON);
	while (current_node)
	{
		if (current_node->num == num)
			print_on_exit(st, ERROR, PRINT_ON);
		current_node = current_node->next;
	}
	temp = ft_nodenew(num);
	if (!st->stack_a)
	{
		st->stack_a = temp;
		st->tail_a = temp;
	}
	else
		ft_nodeadd_end(&st->tail_a, temp);
	return (num);
}

int	check_if_sorted(t_struct *st)
{
	t_node	*current;
	int		flag;

	flag = 1;
	current = st->stack_a;
	if (st->stack_a)
	{
		while (current->next)
		{
			if (current->num > current->next->num)
				flag = 0;
			current = current->next;
		}
	}
	return (flag);
}

char	**init_str_argv(t_struct *st, char **argv, int *argc)
{
	char	**temp;

	temp = argv;
	while (*(*temp) == ' ')
		(*temp)++;
	if (*(*temp) != '\0')
	{
		argv = ft_strsplit(*argv, ' ', argc);
		st->argc = *argc;
		st->argv = argv;
	}
	else
		exit(1);
	return (argv);
}

int	check_push_conditions(t_struct *st)
{
	int	res;

	res = 0;
	if (st->stack_b->num < st->stack_a->num
		&& st->stack_b->num > st->tail_a->num)
		res = 1;
	if (st->stack_b->num > st->max && st->stack_a->num == st->min)
	{
		res = 1;
		st->max = st->stack_b->num;
	}
	if (st->stack_b->num < st->stack_a->num && st->stack_a->num == st->min)
	{
		res = 1;
		st->min = st->stack_b->num;
	}
	return (res);
}
