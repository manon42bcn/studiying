/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:00:39 by mporras           #+#    #+#             */
/*   Updated: 2022/01/04 22:00:46 by mporras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_boxes.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_printer(int **dta)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < N)
	{
		x = 0;
		while (x < N)
		{
			c = (dta[y][x] % 10) + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			x++;
		}
		y++;
		if (y < N)
			write(1, "\n", 1);
	}
}

int	ft_atoi(char *str)
{
	int		rst[2];
	int		i;

	rst[0] = 0;
	rst[1] = 1;
	i = 0;
	while (str[i] >= 0 && str[i] <= 32)
			i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			rst[1] = rst[1] * -1;
		i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (rst[1] * rst[0]);
		else if (str[i] >= '0' && str[i] <= '9')
			rst[0] = rst[0] * 10 + (str[i] - '0');
		i++;
	}
	return (rst[1] * rst[0]);
}
