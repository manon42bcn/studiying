/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 01:35:54 by mporras           #+#    #+#             */
/*   Updated: 2022/01/09 01:35:57 by mporras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_boxes.h"

void	ft_clear_elem(void *elem)
{
	elem = NULL;
	free(elem);
}

void	ft_list_clear(t_perms *begin_list, void (*free_fct)(void *))
{
	t_perms	*next;

	while (begin_list)
	{
		next = begin_list->next;
		begin_list->next = NULL;
		(*free_fct)(begin_list);
		begin_list = next;
	}
	begin_list = NULL;
}

void	ft_free_mem(t_perms *perms, t_boxes *solve)
{
	ft_list_clear(perms, &ft_clear_elem);
	free(solve->solve);
	free(solve->clues);
	free(solve);
}
