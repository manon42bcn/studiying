/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 00:47:55 by mporras           #+#    #+#             */
/*   Updated: 2022/01/05 00:47:57 by mporras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_boxes.h"

int	ft_view_left(int *perm)
{
	int		shadow;
	int		views;
	int		i;

	i = -1;
	views = 0;
	while (++i < N)
	{
		if (perm[i] == 0)
			return (0);
		if (i == 0)
		{
			shadow = perm[i];
			views++;
		}
		else
		{
			if (perm[i] > shadow)
			{
				shadow = perm[i];
				views++;
			}
		}
	}
	return (views);
}

int	ft_view_right(int *perm)
{
	int		shadow;
	int		views;
	int		i;

	i = N - 1;
	views = 0;
	while (i >= 0)
	{
		if (i == N -1)
		{
			shadow = perm[i];
			views++;
		}
		else
		{
			if (perm[i] > shadow)
			{
				shadow = perm[i];
				views++;
			}
		}
	i--;
	}
	return (views);
}

void	ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_perms(int *source, int k, t_perms **perm_list)
{
	int	i;

	i = k;
	if (k == N - 1)
		ft_list_push_front(perm_list, source);
	else
	{
		while (i < N)
		{
			ft_swap(&source[i], &source[k]);
			ft_perms(source, k + 1, perm_list);
			ft_swap(&source[i], &source[k]);
			i++;
		}
	}
}
