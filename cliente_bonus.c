/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliente_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:51:07 by yugao             #+#    #+#             */
/*   Updated: 2024/02/07 22:10:14 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_msg(pid_t pid, char *msg)
{
	unsigned char	c;
	int				num_bit;

	while (*msg)
	{
		c = *msg;
		num_bit = 7;
		while (num_bit >= 0)
		{
			if (c & (1 << num_bit))
				kill (pid, SIGUSR1);
			else
				kill (pid, SIGUSR2);
			num_bit --;
			usleep (300);
		}
		msg ++;
	}
}

static void	receive_msg(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd ("Received !\n", 1);
}

static void	initsig(void)
{
	struct sigaction	init;

	init.sa_handler = receive_msg;
	init.sa_flags = SA_SIGINFO;
	if (sigaction (SIGUSR1, &init, NULL) == -1)
		exit (EXIT_FAILURE);
	if (sigaction (SIGUSR2, &init, NULL) == -1)
		exit (EXIT_FAILURE);
}

int	main(int arc, char **arg)
{
	pid_t	pid;

	initsig ();
	if (arc <= 2 || arc >= 4)
	{
		ft_putstr_fd ("No ha introducido los argumentos correctos !\n", 1);
		return (1);
	}
	pid = ft_atoi (arg[1]);
	if (pid <= 0)
	{
		ft_putstr_fd ("No ha sido extraido PID con exito !\n", 1);
		return (1);
	}
	send_msg (pid, arg[2]);
	return (0);
}
