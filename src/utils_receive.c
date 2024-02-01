/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_receive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:34:55 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/26 13:58:57 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_handle_signal(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("🛰️  Client: received SIGUSR1!\n");
	else if (sig == SIGUSR2)
		ft_printf("🛰️  Client: received SIGUSR2!\n");
}

char	*ft_strjoin_clr(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	if (s1 && s2)
	{
		str = ft_calloc_set_zero(sizeof(char), \
		(ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!str)
			return (NULL);
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		while (s2[j])
			str[i++] = s2[j++];
		str[i] = '\0';
		free(s1);
	}
	return (str);
}

void	ignore_signal(int sig)
{
	(void)sig;
}
