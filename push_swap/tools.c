/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 00:49:08 by leo               #+#    #+#             */
/*   Updated: 2022/03/17 20:46:09 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_struct(t_struct *st)
{
	st->op_list = NULL;
	st->stack_a = NULL;
	st->stack_b = NULL;
	st->tail_a = NULL;
	st->tail_b = NULL;
}

void	validate_argv(t_struct *st, char *argv)
{
	t_dlist	*current_node;
	t_dlist	*temp;
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
	temp = ft_dlstnew(argv, len);
	if (st->stack_a == NULL)
	{
		st->stack_a = temp;
		st->tail_a = temp;
	}	
	else
		ft_dlstaddfront(&st->stack_a, temp);
}

int	check_if_sorted(t_struct *st)
{
	t_dlist	*current_node;
	int		temp;
	int		flag;

	flag = 1;
	current_node = st->stack_a;
	if (current_node != NULL)
	{
		while (current_node->next != NULL)
		{
			temp = ft_atoi(current_node->content);
			if (temp > ft_atoi(current_node->next->content))
				flag = 0;
			current_node = current_node->next;
		}
	}
	if (st->stack_b != NULL)
		flag = 0;
	return (flag);
}
