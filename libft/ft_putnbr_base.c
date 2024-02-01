/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitenner <vitenner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:20:00 by vitenner          #+#    #+#             */
/*   Updated: 2023/10/29 17:32:36 by vitenner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_base_string(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i;
		while (str[j] != '\0')
		{
			if (str[i] == str[j + 1] || str[i] == '+' || str[i] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	baselen;

	baselen = ft_strlen(base);
	if ((baselen <= 1) || (ft_check_base_string(base) == 0))
		return ;
	if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_base(-(nbr / baselen), base);
	}
	else if (nbr / baselen != 0)
	{
		ft_putnbr_base(nbr / baselen, base);
	}
	ft_putchar_fd(base[ft_abs((int)nbr % baselen)], 1);
}
