/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:38:05 by areheman          #+#    #+#             */
/*   Updated: 2022/04/26 13:01:35 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./printf/ft_printf.h"
# include <signal.h>

typedef struct s_msg
{
	char	c;
	size_t	l;
}				t_msg;

#endif 
