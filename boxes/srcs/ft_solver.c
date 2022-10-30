/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 03:05:28 by mporras           #+#    #+#             */
/*   Updated: 2022/01/08 03:05:31 by mporras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_boxes.h"

void	ft_permcpy(t_boxes *solve, t_perms *perms, int deep)
{
	int	i;

	i = 0;
	while (i < N)
	{
		solve->solve[i][deep] = perms->perm[i];
		i++;
	}
}

void	ft_perm_clean(t_boxes *solve, int deep)
{
	int	i;

	i = -1;
	while (++i < N)
		solve->solve[i][deep] = 0;
}

void	ft_solver(t_boxes *solve, t_perms *perms, int deep)
{
	t_perms	*searching;

	if (deep == N)
	{
		if (solve->solved == 1)
			ft_putstr("\n-----------\n");
		if (ft_check_box(solve, (N - 1)) == 1)
		{
			ft_printer(solve->solve);
			solve->solved = 1;
		}
	}
	while (deep < N)
	{
		searching = perms;
		while (searching)
		{
			if (solve->clues[0][deep] == searching->views[0]
				&& solve->clues[1][deep] == searching->views[1])
			{
				ft_permcpy(solve, searching, deep);
				if (ft_check_box(solve, deep) == 1)
					ft_solver(solve, perms, deep + 1);
				ft_perm_clean(solve, deep);
			}
			searching = searching->next;
		}
		deep++;
	}
}
