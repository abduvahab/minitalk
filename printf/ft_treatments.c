/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:07:41 by areheman          #+#    #+#             */
/*   Updated: 2022/04/02 14:38:25 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_in_types(int c)
{
	if (ft_strchr("cspdiuxX%", c))
		return (1);
	return (0);
}

int	ft_treatments(int c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_treat_char(va_arg(args, int));
	else if (c == 's')
		count = ft_treat_str(va_arg(args, char *));
	else if (c == 'p')
		count = ft_treat_point(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		count = ft_treat_demi(va_arg(args, int));
	else if (c == 'u')
		count = ft_treat_uint((unsigned int)va_arg(args, unsigned int));
	else if (c == 'x')
		count = ft_treat_hexa(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		count = ft_treat_hexa(va_arg(args, unsigned int), 1);
	else if (c == '%')
		count = ft_treat_percent();
	return (count);
}
