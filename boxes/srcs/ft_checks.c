/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:32:48 by mporras           #+#    #+#             */
/*   Updated: 2022/01/07 20:32:50 by mporras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_boxes.h"

int	ft_check_box(t_boxes *solve, int deep)
{
	int	y;
	int	x;
	int	box;

	y = 0;
	while (y < N)
	{
		x = -1;
		box = solve->solve[y][deep];
		if (deep == (N - 1))
		{
			if (ft_view_left(solve->solve[y]) != solve->clues[2][y]
				|| ft_view_right(solve->solve[y]) != solve->clues[3][y])
				return (0);
		}
		while (++x < deep)
		{
			if (solve->solve[y][x] == box)
				return (0);
		}
		y++;
	}
	return (1);
}

int	ft_check_final(t_boxes *solve)
{
	int	y;
	int	x;
	int	box;

	y = 0;
	while (y < N)
	{
		x = 0;
		box = solve->solve[y][x];
		if (box == 0)
			return (0);
		while (x < N)
		{
			if (solve->solve[y][x] == 0 || solve->solve[y][x] == box)
				return (0);
			x++;
		}
		if (ft_view_left(solve->solve[y]) != solve->clues[2][y]
			|| ft_view_right(solve->solve[y]) != solve->clues[3][y])
			return (0);
		y++;
	}
	return (1);
}
