/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:51:16 by areheman          #+#    #+#             */
/*   Updated: 2022/04/02 14:26:16 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

# define BASE_BINARY		"01"
# define BASE_DECIMAL	"0123456789"
# define BASE_OCTAL		"01234567"
# define BASE_HEX_LOW	"0123456789abcdef"
# define BASE_HEX_UPP	"0123456789ABCDEF"

int		ft_printf(const char *fmt, ...);
int		ft_is_in_types(int c);
int		ft_is_in_flags(int c);
int		ft_treatments(int c, va_list args);
int		ft_treat_char(int c);
int		ft_treat_percent(void);
int		ft_treat_str(char *s);
int		ft_treat_demi(int c);
int		ft_treat_point(unsigned long l);
char	*ft_convert(unsigned long l, char *base);
int		ft_treat_hexa(unsigned int n, int flag);
int		ft_treat_uint(unsigned int n);

#endif 
