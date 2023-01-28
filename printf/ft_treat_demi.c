/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_demi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:06:43 by areheman          #+#    #+#             */
/*   Updated: 2022/03/31 15:29:33 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_demi(int c)
{
	char	*s;
	size_t	size;

	s = ft_itoa(c);
	ft_putstr_fd(s, 1);
	size = ft_strlen(s);
	free(s);
	return (size);
}
