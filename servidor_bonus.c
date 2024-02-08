/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servidor_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:51:12 by yugao             #+#    #+#             */
/*   Updated: 2024/02/07 22:42:49 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	receive_msg_ex(int sig, siginfo_t *info, void *contest)
{
	static char	c;
	static int	num = 8;

	num --;
	if (sig == SIGUSR1)
		c |= (1 << num);
	if (num == 0)
	{
		ft_putchar_fd (c, 1);
		c = 0;
		num = 8;
		if (kill (info->si_pid, SIGUSR1) == -1)
			exit (EXIT_FAILURE);
	}
}

static void	initsig(void)
{
	struct sigaction	init;

	init.sa_sigaction = receive_msg_ex;
	init.sa_flags = SA_SIGINFO;
	if (sigaction (SIGUSR1, &init, NULL) == -1)
		exit (EXIT_FAILURE);
	if (sigaction (SIGUSR2, &init, NULL) == -1)
		exit (EXIT_FAILURE);
}

int	main(void)
{
	pid_t	pid;

	initsig ();
	pid = getpid();
	if (!pid)
		return (1);
	printf ("PID: %d\n", getpid ());
	while (1)
		pause ();
	return (0);
}
