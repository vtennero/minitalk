/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:01:15 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/26 15:34:29 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_signal	g_signal = {{0}, 0, NULL};

int	is_all_zeros(const t_signal *msg)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (msg->bit_buffer[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

void	server_handle_sigusr1(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	server_build_message(sig);
	if (kill(siginfo->si_pid, SIGUSR1) == -1)
		ft_printf("Failed to send SIGUSR1 back");
}

void	server_handle_sigusr2(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	server_build_message(sig);
	if (kill(siginfo->si_pid, SIGUSR1) == -1)
		ft_printf("Failed to send SIGUSR1 back");
}

void	server_build_message(int sig)
{
	if ((sig == SIGUSR1))
		g_signal.bit_buffer[g_signal.bit_count % 32] = '0';
	else
		g_signal.bit_buffer[g_signal.bit_count % 32] = '1';
	g_signal.bit_count++;
	if (!(g_signal.bit_count % 32) && g_signal.bit_count)
	{
		if (is_all_zeros(&g_signal))
		{
			print_server_output(g_signal.message);
			reset_signal(&g_signal, 0);
		}
		g_signal.bit_buffer[32] = '\0';
		if (!g_signal.message)
			g_signal.message = ft_strndup(g_signal.bit_buffer, 32);
		else
			g_signal.message = ft_strjoin_clr(g_signal.message, \
			g_signal.bit_buffer);
		reset_signal(&g_signal, 1);
	}
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	sa1.sa_sigaction = server_handle_sigusr1;
	sigemptyset(&sa1.sa_mask);
	sa1.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa1, NULL);
	sa2.sa_sigaction = server_handle_sigusr2;
	sigemptyset(&sa2.sa_mask);
	sa2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa2, NULL);
	ft_printf("📡 Server: Ready to receive signals. PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
