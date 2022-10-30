/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_recursive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:11:01 by mporras-          #+#    #+#             */
/*   Updated: 2022/10/02 15:11:40 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

void ft_itoa_build(long int nbr, int *steps, char **rst)
{
	if (nbr < 10)
	{
		*rst = (char *)malloc(sizeof(char) * (steps[0] + 2));
		if (*rst == NULL)
			return ;
		(*rst)[steps[0] + 1] = '\0';
		if (steps[1] == 1)
			(*rst)[0] = '-';
		(*rst)[steps[1]] = (nbr % 10) + '0';
		steps[1]+=1;
		return ;
	}
	steps[0]++;
	ft_itoa_build(nbr / 10, steps, rst);
	if (*rst == NULL)
		return ;
	(*rst)[steps[1]] = (nbr % 10) + '0';
	steps[1]++;
}

char *ft_itoa(int n)
{
	char	*rst;
	int		stp_ind[2];

	stp_ind[0] = 0;
	stp_ind[1] = 0;
	rst = NULL;
	if (n < 0)
	{
		stp_ind[0] = 1;
		stp_ind[1] = 1;
		ft_itoa_build((long int)n * -1, &stp_ind[0], &rst);
	}
	else
		ft_itoa_build((long int)n, &stp_ind[0], &rst);
	return (rst);
}

int main()
{
	char *toItoa;

	toItoa = ft_itoa(INT_MIN);
	printf("%d <- min [ %s ] <- str\n", INT_MIN, toItoa);
	free(toItoa);
	toItoa = ft_itoa(INT_MAX);
	printf("%d <- max [ %s ] <- str\n", INT_MAX, toItoa);
	free(toItoa);
	toItoa = ft_itoa(25889);
	printf("%d <- int [ %s ] <- str\n", 25889, toItoa);
	toItoa = ft_itoa(-1);
	printf("%d <- int [ %s ] <- str\n", -1, toItoa);
	toItoa = ft_itoa(0);
	printf("%d <- int [ %s ] <- str\n", 0, toItoa);
	return (0);
}
