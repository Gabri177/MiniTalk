/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servidor_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:51:12 by yugao             #+#    #+#             */
/*   Updated: 2024/02/08 03:43:13 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_msg_ex(int sig, siginfo_t *info, void *contest)
{
	static char	c;
	static int	num = 8;

	num --;
	(void)contest;
	if (sig == SIGUSR1)
		c |= (1 << num);
	if (num == 0)
	{
		ft_putchar_fd (c, 1);
		c = 0;
		num = 8;
		if (kill (info->si_pid, SIGUSR1) == -1)
		{
			ft_putstr_fd ("Seed Feedback Wrong !\n", 1);
			exit (EXIT_FAILURE);
		}
	}
}

static void	initsig(void)
{
	struct sigaction	init;

	init.sa_sigaction = receive_msg_ex;
	init.sa_flags = SA_SIGINFO;
	sigemptyset (&init.sa_mask);
	sigaddset (&init.sa_mask, SIGUSR1);
	sigaddset (&init.sa_mask, SIGUSR2);
	if (sigaction (SIGUSR1, &init, NULL) == -1)
	{
		ft_putstr_fd ("Iniciation of Signal_1: ERROR \n", 1);
		exit (EXIT_FAILURE);
	}
	if (sigaction (SIGUSR2, &init, NULL) == -1)
	{
		ft_putstr_fd ("Iniciation of Signal_2: ERROR \n", 1);
		exit (EXIT_FAILURE);
	}
}

int	main(void)
{
	pid_t	pid;

	initsig ();
	pid = getpid();
	if (!pid)
	{
		ft_putstr_fd ("Get PID Wrong! \n", 1);
		return (1);
	}
	ft_putnbr_fd (pid, 1);
	while (1)
		pause ();
	return (0);
}
