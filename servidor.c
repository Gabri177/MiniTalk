/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servidor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:32:39 by yugao             #+#    #+#             */
/*   Updated: 2024/02/09 21:59:05 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_msg(int sig, siginfo_t *info, void *contest)
{
	static char	c;
	static int	num = 8;

	num --;
	(void)contest;
	(void)info;
	if (sig == SIGUSR1)
		c |= (1 << num);
	if (num == 0)
	{
		ft_putchar_fd (c, 1);
		c = 0;
		num = 8;
	}
}

static void	initsig(void)
{
	struct sigaction	init;

	init.sa_sigaction = receive_msg;
	sigemptyset (&init.sa_mask);
	sigaddset (&init.sa_mask, SIGUSR1);
	sigaddset (&init.sa_mask, SIGUSR1);
	init.sa_flags = SA_SIGINFO;
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

	pid = getpid ();
	if (pid <= 0)
	{
		ft_putstr_fd ("Get PID WRONG ! \n", 1);
		return (1);
	}
	initsig ();
	ft_putnbr_fd (pid, 1);
	while (1)
		pause ();
	return (0);
}
