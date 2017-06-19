/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:18:26 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/27 11:58:33 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	erase_4(t_lem *lem, int i, int tmp)
{
	if (lem->tmp_pipes)
	{
		free(lem->tmp_pipes);
		lem->tmp_pipes = NULL;
	}
	if (lem->ahill)
	{
		free(lem->ahill);
		lem->ahill = NULL;
	}
	if (lem->coor)
	{
		tmp = ft_ptrlen(lem->coor);
		while (i <= tmp)
		{
			free(lem->coor[i]);
			++i;
		}
		free(lem->coor);
	}
	if (lem)
		free(lem);
}

void	erase_3(t_lem *lem, int i, int tmp)
{
	if (lem->pipes)
	{
		tmp = ft_ptrlen(lem->pipes);
		while (i <= tmp)
			free(lem->pipes[i++]);
		free(lem->pipes);
	}
	i = 0;
	if (lem->rooms)
	{
		while (i <= lem->nb_rooms)
			free(lem->rooms[i++]);
		free(lem->rooms);
	}
	i = 0;
	if (lem->asso)
	{
		while (i < lem->nb_pipes_tot)
			free(lem->asso[i++]);
		free(lem->asso);
	}
}

void	erase_2(t_lem *lem, int i)
{
	if (lem->first_rooms)
		free(lem->first_rooms);
	if (lem->empty_rooms)
		free(lem->empty_rooms);
	if (lem->start)
		free(lem->start);
	if (lem->end)
		free(lem->end);
	if (lem->nb_pipes)
		free(lem->nb_pipes);
	if (lem->last_room)
		free(lem->last_room);
	if (lem->str)
		free(lem->str);
	if (lem->tmp)
		free(lem->tmp);
	if (lem->ants)
	{
		while (i < lem->nb_ants)
			free(lem->ants[i++]);
		free(lem->ants);
	}
}

void	erase(t_lem *lem)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	if (lem->paths)
	{
		tmp = ft_ptrlen(lem->paths);
		while (i <= lem->nb_paths)
			free(lem->paths[i++]);
		free(lem->paths);
	}
	i = 0;
	if (lem->anthill)
	{
		tmp = ft_ptrlen(lem->anthill);
		while (i <= tmp)
			free(lem->anthill[i++]);
		free(lem->anthill);
	}
	erase_2(lem, 0);
	erase_3(lem, 0, 0);
	erase_4(lem, 0, 0);
}
