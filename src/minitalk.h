/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:00:40 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/26 15:34:35 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>
# include <sys/types.h>

typedef struct s_signal {
	char	bit_buffer[33];
	int		bit_count;
	char	*message;
}	t_signal;

/*
** ------------------------- RECEIVE -------------------------
*/
void			client_handle_signal(int sig);
void			server_build_message(int sig);
void			server_handle_sigusr1(int sig, siginfo_t \
*siginfo, void *context);
void			server_handle_sigusr2(int sig, siginfo_t \
*siginfo, void *context);
char			*ft_strjoin_clr(char *s1, char *s2);
/*
** ------------------------- SEND -------------------------
*/
void			client_send_signals(const unsigned char \
*binaryArray, size_t binarySize, pid_t targetPID);
/*
** ------------------------- BITMAP -------------------------
*/
unsigned char	*build_binary(const char *str, size_t *binarySize);
void			print_server_output(const char *binaryString);
void			reset_signal(t_signal *sm, int count_reset);
/*
** ------------------------- DEBUG -------------------------
*/
void			debug_print_client_array(const unsigned char \
*binaryArray, size_t binarySize);

#endif
