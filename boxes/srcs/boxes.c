/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:14:45 by mporras           #+#    #+#             */
/*   Updated: 2022/01/04 21:14:47 by mporras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_boxes.h"

int	main(int argc, char **argv)
{
	t_boxes	*process;
	t_perms	*perms;
	int		*set;
	int		i;

	if ((argc - 1) % (4 * N) != 0)
	{
		ft_putstr("Input Error.\n");
		return (0);
	}
	i = 0;
	set = ft_create_set();
	perms = NULL;
	ft_perms(set, 0, &perms);
	process = ft_process_data(argv);
	ft_solver(process, perms, 0);
	if (process->solved == 0)
		ft_putstr("NO HAY SOLVE\n");
	ft_free_mem(perms, process);
	return (0);
}
