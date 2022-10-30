/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 02:31:13 by mporras           #+#    #+#             */
/*   Updated: 2022/01/06 02:31:15 by mporras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_boxes.h"

int	*ft_create_set(void)
{
	int	i;
	int	*rst;

	i = 0;
	rst = (int *)malloc(sizeof(int) * N);
	if (rst == NULL)
		return (NULL);
	while (i < N)
	{
		rst[i] = i + 1;
		i++;
	}
	return (rst);
}

t_boxes	*ft_create_solve(t_boxes *process)
{
	int	y;

	y = 0;
	process = (t_boxes *)malloc(sizeof(t_boxes));
	if (process == NULL)
		return (NULL);
	process->clues = (int **)malloc(sizeof(int *) * (4 * N));
	if (process->clues == NULL)
		return (NULL);
	process->solve = (int **)malloc(sizeof(int *) * (N * N));
	if (process->solve == NULL)
		return (NULL);
	while (y < 4)
	{
		process->clues[y] = (int *)malloc(sizeof(int) * N);
		if (process->clues[y] == NULL)
			return (NULL);
		y++;
	}
	return (process);
}

void	ft_load_empty_solve(t_boxes *process)
{
	int		y;
	int		x;

	y = 0;
	while (y < N)
	{
		x = 0;
		while (x < N)
		{
			process->solve[y] = (int *)malloc(sizeof(int) * N);
			if (process->solve[y] == NULL)
				break ;
			process->solve[y][x] = 0;
			x++;
		}
		y++;
	}
}

t_boxes	*ft_process_data(char **argv)
{
	t_boxes	*process;
	int		y;
	int		x;
	int		i;

	y = 0;
	i = 0;
	process = NULL;
	process = ft_create_solve(process);
	if (process == NULL)
		return (NULL);
	while (y < 4)
	{
		x = 0;
		while (x < N)
		{
			process->clues[y][x] = ft_atoi(argv[i + 1]);
			x++;
			i++;
		}
		y++;
	}
	ft_load_empty_solve(process);
	process->solved = 0;
	return (process);
}
