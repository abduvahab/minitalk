/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:19:57 by areheman          #+#    #+#             */
/*   Updated: 2022/04/02 13:04:38 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_hexa(unsigned int n, int flag)
{
	unsigned long	l;
	size_t			count;
	char			*arr;

	l = (unsigned long)n;
	if (flag == 0)
	{
		arr = ft_convert(l, BASE_HEX_LOW);
	}
	else
	{
		arr = ft_convert(l, BASE_HEX_UPP);
	}
	ft_putstr_fd(arr, 1);
	count = ft_strlen(arr);
	free(arr);
	return (count);
}
