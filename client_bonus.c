/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:37:15 by areheman          #+#    #+#             */
/*   Updated: 2022/04/26 12:58:11 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	rec_comple(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("we have received your message!\n");
}

void	sen_char_bybit(int pid, char *s)
{
	size_t	i;
	int		t;

	i = 0;
	while (i <= ft_strlen(s))
	{
		t = 0;
		while (t < 7)
		{
			if ((s[i] >> t) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			t++;
			usleep(80);
		}
		i++;
	}
	signal(SIGUSR2, rec_comple);
	pause();
}

void	sen_c_pid(int s_pid, int c_pid)
{
	char	*s;
	size_t	i;
	int		t;

	s = ft_itoa(c_pid);
	i = 0;
	while (i <= ft_strlen(s))
	{
		t = 0;
		while (t < 7)
		{
			if ((s[i] >> t) & 1)
				kill(s_pid, SIGUSR2);
			else
				kill(s_pid, SIGUSR1);
			t++;
			usleep(100);
		}
		i++;
	}
	free(s);
}

int	main(int an, char **as)
{
	int	i;

	if (an != 3)
	{
		ft_printf("please enter three arguments!\n");
		return (0);
	}
	i = 0;
	while (as[1][i])
	{
		if (!ft_isdigit(as[1][i]))
		{
			ft_printf("illegal pid number!\n");
			return (0);
		}
		i++;
	}
	sen_c_pid(ft_atoi(as[1]), getpid());
	sen_char_bybit(ft_atoi(as[1]), as[2]);
	return (0);
}
