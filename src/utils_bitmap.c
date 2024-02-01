/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bitmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:37:22 by vitenner          #+#    #+#             */
/*   Updated: 2024/01/26 15:34:31 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*build_binary(const char *str, size_t *b_size)
{
	size_t			i;
	size_t			j;
	int				k;
	unsigned char	*new_binary_array;

	i = 0;
	j = 0;
	*b_size = ft_strlen(str) * 4;
	new_binary_array = (unsigned char *)malloc(*b_size * sizeof(unsigned char));
	if (new_binary_array == NULL)
		return (NULL);
	while (i < *b_size / 4)
	{
		k = 3;
		while (k >= 0)
		{
			new_binary_array[j + k] = \
			((unsigned int)str[i] >> (8 * (3 - k))) & 0xFF;
			--k;
		}
		++i;
		j += 4;
	}
	return (new_binary_array);
}

void	reset_signal(t_signal *sm, int count_reset)
{
	if (sm == NULL)
		return ;
	sm->bit_buffer[0] = '\0';
	if (!count_reset)
	{
		if (sm->message != NULL)
		{
			free(sm->message);
			sm->message = NULL;
			sm->bit_count = 0;
		}
	}
}

char	decode_character(const char *binaryString, size_t start_index)
{
	unsigned char	character;
	unsigned char	byte;
	size_t			str_index;
	int				bit_index;
	int				bit;

	character = 0;
	bit_index = 0;
	while (bit_index < 32)
	{
		byte = 0;
		bit = 0;
		while (bit < 8)
		{
			byte <<= 1;
			str_index = start_index + bit_index + bit;
			if (binaryString[str_index] == '1') 
				byte |= 1;
			bit++;
		}
		if (bit_index == 24) 
			character = byte;
		bit_index += 8;
	}
	return (character);
}

char	*allocate_text_buffer(size_t num_chars)
{
	char	*text;

	text = (char *)malloc(num_chars + 1);
	if (text == NULL)
		return (NULL);
	return (text);
}

void	print_server_output(const char *binaryString)
{
	size_t	num_chars;
	size_t	char_index;
	size_t	start_index;
	char	*text;
	char	character;

	num_chars = ft_strlen(binaryString) / 32;
	text = NULL;
	text = allocate_text_buffer(num_chars);
	char_index = 0;
	if (text != NULL)
	{
		while (char_index < num_chars) 
		{
			start_index = char_index * 32;
			character = decode_character(binaryString, start_index);
			text[char_index] = character;
			char_index++;
		}
		text[num_chars] = '\0';
		ft_printf("%s\n", text);
		free(text);
	}
}
