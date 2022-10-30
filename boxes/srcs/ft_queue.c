/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 02:02:07 by mporras           #+#    #+#             */
/*   Updated: 2022/01/05 02:02:11 by mporras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_boxes.h"

void	ft_copy_perm(int *source, int *dest)
{
	int	i;

	i = -1;
	while (++i < N)
		dest[i] = source[i];
}

t_perms	*ft_create_elem(int *perm)
{
	t_perms	*elem;

	elem = (t_perms *)malloc(sizeof(t_perms));
	elem->perm = (int *)malloc(sizeof(int) * N);
	if (elem == NULL || elem->perm == NULL)
		return (NULL);
	else
	{
		ft_copy_perm(perm, elem->perm);
		elem->views[0] = ft_view_left(perm);
		elem->views[1] = ft_view_right(perm);
		elem->next = NULL;
	}
	return (elem);
}

void	ft_list_push_front(t_perms **begin_list, int *data)
{
	t_perms	*elem;

	if (*begin_list == NULL)
		*begin_list = ft_create_elem(data);
	else
	{
		elem = ft_create_elem(data);
		elem->next = *begin_list;
		*begin_list = elem;
	}
}
