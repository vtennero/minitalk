/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_send.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:37:28 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/26 13:09:57 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_eos(pid_t target_pid)
{
	int	bits_sent;
	int	bit;

	bits_sent = 0;
	bit = 0;
	while (bit < 32)
	{
		kill(target_pid, SIGUSR1);
		++bits_sent;
		usleep(10000);
		++bit;
	}
	ft_printf("🛰️  Client: Sent %d bits (\\0 character)\n", bits_sent);
}

void	client_send_signals(const unsigned char *arr, size_t s, pid_t t_pid)
{
	int				bits_sent;
	int				bit;
	unsigned char	bit_value;
	size_t			i;

	bits_sent = 0;
	i = 0;
	while (i < s)
	{
		bit = 7;
		while (bit >= 0)
		{
			bit_value = (arr[i] >> bit) & 1;
			if (bit_value == 0)
				kill(t_pid, SIGUSR1);
			else
				kill(t_pid, SIGUSR2);
			++bits_sent;
			usleep(10000);
			--bit;
		}
		++i;
	}
	ft_printf("🛰️  Client: Sent %d bits\n", bits_sent);
	send_eos(t_pid);
}
