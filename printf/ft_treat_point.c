/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:55:44 by areheman          #+#    #+#             */
/*   Updated: 2022/04/02 14:30:01 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_point(unsigned long l)
{
	char	*arr;
	size_t	count;

	arr = ft_convert(l, BASE_HEX_LOW);
	count = ft_strlen(arr);
	write (1, "0x", 2);
	ft_putstr_fd(arr, 1);
	free(arr);
	return (count + 2);
}
