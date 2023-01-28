/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:44:31 by areheman          #+#    #+#             */
/*   Updated: 2022/04/26 12:10:10 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sen_char_bybit(int pid, char *s)
{
	size_t	i;
	size_t	l;
	int		sf;

	l = ft_strlen(s);
	i = 0 ;
	while (i <= l)
	{
		sf = 0;
		while (sf < 7)
		{
			if ((s[i] >> sf) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			sf++;
			usleep(100);
		}
		i++;
	}
}

int	main(int av, char **as)
{
	int	i;

	if (av == 3)
	{
		i = 0;
		while (as[1][i])
		{
			if (!ft_isdigit(as[1][i]))
			{
				ft_putstr_fd("illegal pid number\n", 1);
				return (-1);
			}
			i++;
		}
		sen_char_bybit(ft_atoi(as[1]), as[2]);
		return (0);
	}
	else
	{
		ft_putstr_fd("please enter three arguments!\n", 1);
		return (-1);
	}
}
