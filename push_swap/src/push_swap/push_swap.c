/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:38:59 by leo               #+#    #+#             */
/*   Updated: 2022/07/30 01:53:31 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	init_intarrays(t_nums *arr, int size)
{
	arr->lis_head = NULL;
	arr->lis_tail = NULL;
	arr->lis = (int *)malloc(sizeof(int) * size);
	arr->num = (int *)malloc(sizeof(int) * size);
	if (!arr->num || !arr->lis)
		exit (1);
	arr->size = size;
	arr->mean = 0;
	while (size--)
		arr->lis[size] = 1;
}

static char	**init_str_argv(char *str, int *argc)
{
	char	**argv;
	char	**temp;

	argv = ft_strsplit(str, ' ');
	temp = argv;
	*argc = 1;
	while (*(temp++))
		(*argc)++;
	return (argv);
}

int	main(int argc, char **argv)
{
	t_struct	st;
	t_nums		arr;
	int			*temp;

	if (argc > 1)
	{
		argv++;
		if (argc == 2)
			argv = init_str_argv(argv[0], &argc);
		initialize_struct(&st);
		init_intarrays(&arr, argc - 1);
		temp = arr.num;
		while (--argc)
		{
			*temp = validate_argv(&st, *(argv++));
			temp++;
		}
		get_lis_nums(&st, &arr);
		// sort_list(&st, &arr);
		ft_printf("mean: %d min: %d max: %d\n", arr.mean, st.min, st.max);
		print_list(&st);
	}
	return (0);
}
