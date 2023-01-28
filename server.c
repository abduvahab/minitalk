/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areheman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:44:51 by areheman          #+#    #+#             */
/*   Updated: 2022/04/26 12:10:47 by areheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	rec_char_bybit(int sig)
{	
	static t_msg	r_msg;

	if (r_msg.l == 0)
		r_msg.c = 0;
	r_msg.c += ((sig & 1) << r_msg.l);
	r_msg.l++;
	if (r_msg.l == 7)
	{
		ft_putchar_fd(r_msg.c, 1);
		r_msg.c = 0;
		r_msg.l = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("server pid:", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR1, rec_char_bybit);
		signal(SIGUSR2, rec_char_bybit);
		pause();
	}
}
