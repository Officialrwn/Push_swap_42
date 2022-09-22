/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:49:29 by leotran           #+#    #+#             */
/*   Updated: 2022/09/22 11:20:56 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*convert_uitoa_base(unsigned long long num, \
int base, char *arr, int flag)
{
	unsigned long long	remainder;
	int					i;

	i = ft_uint_base_count(num, base);
	remainder = 0;
	if (flag)
		flag = 55;
	else
		flag = 87;
	while (i-- > 0)
	{
		remainder = num % (unsigned long long)base;
		if (remainder > 9)
			arr[i] = remainder + (unsigned long long)flag;
		else
			arr[i] = remainder + 48;
		num /= base;
	}
	return (arr);
}

char	*ft_uitoa_base(unsigned long long num, int base, int flag)
{
	char	*arr;
	int		count;

	count = ft_uint_base_count(num, base);
	arr = (char *)malloc(sizeof(char) * count + 1);
	if (arr)
	{
		arr[count] = '\0';
		arr = convert_uitoa_base(num, base, arr, flag);
	}
	return (arr);
}
