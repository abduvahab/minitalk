/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:26:49 by areheman          #+#    #+#             */
/*   Updated: 2022/03/31 15:05:51 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_get_size(unsigned long n, size_t radix)
{
	size_t	size;

	size = 0;
	while (1)
	{
		n /= radix;
		size++;
		if (n == 0)
			break ;
	}
	return (size);
}

char	*ft_convert(unsigned long l, char *base)
{
	long long	n;
	size_t		radix;
	char		*arr;
	size_t		size;

	n = l;
	radix = ft_strlen(base);
	size = ft_get_size(n, radix);
	arr = (char *)malloc(sizeof(char) * size + 1);
	if (!arr)
		return (0);
	arr[size] = '\0';
	while (1)
	{
		arr[size - 1] = base[(n % radix)];
		size--;
		n /= radix;
		if (n == 0)
			break ;
	}
	return (arr);
}
