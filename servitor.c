/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servitor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:32:39 by yugao             #+#    #+#             */
/*   Updated: 2024/02/07 20:58:05 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_msg(int sig)
{
	static int	bit_num = 8;
	static char	c;

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
	signal (SIGUSR1, receive_msg);
	signal (SIGUSR2, receive_msg);

	printf ("PID: %d\n", getpid ());
	while (1)
		pause ();
	return (0);
}