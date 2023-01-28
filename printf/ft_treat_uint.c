/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:54:42 by areheman          #+#    #+#             */
/*   Updated: 2022/04/02 13:03:43 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_uint(unsigned int n)
{
	size_t			count;
	char			*arr;

	arr = ft_convert(n, BASE_DECIMAL);
	count = ft_strlen(arr);
	ft_putstr_fd(arr, 1);
	free(arr);
	return (count);
}
