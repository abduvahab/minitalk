/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:16:06 by areheman          #+#    #+#             */
/*   Updated: 2022/04/02 14:16:47 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_str(char *s)
{
	size_t	count;
	char	*arr;

	if (!s)
		arr = ft_strdup("(null)");
	if (s)
		arr = ft_strdup(s);
	ft_putstr_fd(arr, 1);
	count = ft_strlen(arr);
	free(arr);
	return (count);
}
