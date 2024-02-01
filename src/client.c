/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:00:32 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/26 14:13:33 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	run_client(char *user_input, pid_t server_pid)
{
	unsigned char		*binary_array;
	size_t				binary_size;
	struct sigaction	sa;

	binary_array = build_binary(user_input, &binary_size);
	if (binary_array != NULL && server_pid)
	{
		sa.sa_handler = client_handle_signal;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = 0;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		client_send_signals(binary_array, binary_size, server_pid);
		free(binary_array);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("🛰️  Client: Usage: %s <pid> <message>\n", argv[0]);
		return (1);
	}
	if (!(run_client(argv[2], (pid_t)ft_atoi(argv[1]))))
		ft_printf("🛰️  Client: Memory allocation failed.\n");
	return (0);
}
