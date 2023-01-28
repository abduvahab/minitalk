/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:10:59 by areheman          #+#    #+#             */
/*   Updated: 2022/04/02 14:38:01 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_treatfmt(const char *fmt, va_list args)
{
	int	count;

	count = 0;
	while (*fmt)
	{
		if (ft_is_in_types(*fmt))
		{
			count += ft_treatments(*fmt, args);
			break ;
		}
		else
			break ;
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
		{
			count += ft_treatfmt(fmt + 1, args);
			fmt += 1;
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			count++;
		}
		fmt += 1;
	}
	va_end(args);
	return (count);
}
