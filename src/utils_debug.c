/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:35:37 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/26 14:01:40 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	debug_print_client_array_b(const unsigned char *array, size_t size)
{
	size_t	i;
	int		bit;

	if (array != NULL)
	{
		ft_printf("Binary Array:\n");
		i = 0;
		while (i < size)
		{
			bit = 7;
			while (bit >= 0)
			{
				ft_printf("%d", (array[i] >> bit) & 1);
				--bit;
			}
			i++;
		}
		ft_printf("\n");
	}
}

static void	debug_print_client_array_s(const unsigned char *array, size_t size)
{
	size_t	i;
	size_t	j;
	char	*str;
	int		k;

	str = (char *)malloc((size / 4) + 1);
	if (str == NULL)
		return ;
	i = 0;
	j = 0;
	while (i < size / 4)
	{
		k = 0;
		while (k < 4)
		{
			str[i] |= array[j + k] << (8 * (3 - k));
			++k;
		}
		++i;
		j += 4;
	}
	str[size / 4] = '\0';
	ft_printf("%s\n", str);
	free(str);
}

void	debug_print_client_array(const unsigned char *array, size_t size)
{
	debug_print_client_array_b(array, size);
	debug_print_client_array_s(array, size);
}

void	debug_server_print_bits(const t_signal *msg)
{
	int	i;

	ft_printf("bitBuffer contents: |");
	i = 0;
	while (i < 32)
	{
		ft_printf("%c", msg->bit_buffer[i]);
		i++;
	}
	ft_printf("|\n");
}
