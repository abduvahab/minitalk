/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:36:58 by areheman          #+#    #+#             */
/*   Updated: 2022/04/26 12:55:48 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static t_msg	g_ms;

void	get_c_pid(int sig)
{
	if (g_ms.n == 0)
			g_ms.c = 0;
		g_ms.c += ((sig & 1) << g_ms.n);
		g_ms.n++;
	if (g_ms.n == 7)
	{
		if (g_ms.c)
			g_ms.c_pid = ((g_ms.c_pid * 10) + (g_ms.c - 48));
		if (!g_ms.c)
			g_ms.flag = 1;
		g_ms.n = 0;
		g_ms.c = 0;
	}
}

void	rec_char_bybit(int sig)
{
	if (g_ms.flag == 0)
		get_c_pid(sig);
	else
	{
		g_ms.c += ((sig & 1) << g_ms.n);
		g_ms.n++;
		if (g_ms.n == 7)
		{
			ft_printf("%c", g_ms.c);
			if (!g_ms.c)
			{
				usleep(120);
				kill(g_ms.c_pid, SIGUSR2);
				g_ms.flag = 0;
				g_ms.c_pid = 0;
			}
			g_ms.c = 0;
			g_ms.n = 0;
		}
	}
}

int	main(void)
{
	ft_printf("server pid:%d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, rec_char_bybit);
		signal(SIGUSR2, rec_char_bybit);
		pause();
	}
	return (0);
}
