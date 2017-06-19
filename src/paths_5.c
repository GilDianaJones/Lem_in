/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:12:02 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/22 12:46:57 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		init_tmp_pipes(t_lem *lem)
{
	int		i;

	i = 0;
	if (lem->tmp_pipes)
	{
		free(lem->tmp_pipes);
		lem->tmp_pipes = NULL;
	}
	lem->tmp_pipes = (int *)malloc(lem->nb_rooms * sizeof(int));
	while (i < lem->nb_rooms)
	{
		lem->tmp_pipes[i] = lem->nb_pipes[i];
		++i;
	}
}

t_list		*remove_lst(t_list *tmp)
{
	t_list	*temp;

	free(tmp->content);
	tmp->content = NULL;
	temp = tmp;
	tmp = tmp->next;
	free(temp);
	temp = NULL;
	return (tmp);
}

int			*init_tmp_rooms(t_lem *lem, int *avail_rooms)
{
	int		i;
	int		*tmp_rooms;

	i = 0;
	if (!avail_rooms)
		failure(lem);
	if (!(tmp_rooms = (int *)malloc(lem->nb_rooms * sizeof(int))))
		failure(lem);
	while (i < lem->nb_rooms)
	{
		tmp_rooms[i] = avail_rooms[i];
		++i;
	}
	return (tmp_rooms);
}
