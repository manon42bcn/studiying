/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boxes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 21:15:47 by mporras           #+#    #+#             */
/*   Updated: 2022/01/21 00:01:00 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOXES_H
# define FT_BOXES_H

# include <stdlib.h>

typedef struct s_boxes
{
	int	**clues;
	int	**solve;
	int	solved;
}	t_boxes;

typedef struct s_perms
{
	int				*perm;
	int				views[2];
	struct s_perms	*next;	
}	t_perms;

void	ft_putstr(char *str);
void	ft_printer(int **dta);
int		ft_atoi(char *str);
void	ft_perms(int *source, int k, t_perms **perm_list);
int		ft_view_right(int *perm);
int		ft_view_left(int *perm);
void	ft_list_push_front(t_perms **begin_list, int *data);
int		*ft_create_set(void);
t_boxes	*ft_process_data(char **argv);
void	ft_solver(t_boxes *solve, t_perms *perms, int deep);
int		ft_check_box(t_boxes *solve, int deep);
int		ft_check_final(t_boxes *solve);
void	ft_free_mem(t_perms *perms, t_boxes *solve);

#endif
