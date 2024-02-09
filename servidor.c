/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servidor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:32:39 by yugao             #+#    #+#             */
/*   Updated: 2024/02/08 03:43:21 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_msg(int sig)
{
	static int				bit_num = 8;
	static unsigned char	c;

	bit_num --;
	if (sig == SIGUSR1)
		c |= (1 << bit_num);
	if (bit_num == 0)
	{
		ft_putchar_fd (c, 1);
		bit_num = 8;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid ();
	if (pid <= 0)
	{
		ft_putstr_fd ("Get PID WRONG ! \n", 1);
		return (1);
	}
	signal (SIGUSR1, receive_msg);
	signal (SIGUSR2, receive_msg);
	printf ("PID: %d\n", pid);
	while (1)
		pause ();
	return (0);
}
