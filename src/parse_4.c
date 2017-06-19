/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:10:27 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/22 12:37:47 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	get_first_rooms(t_lem *lem, int i, int j, int k)
{
	if (!(lem->first_rooms = (int *)malloc(ft_ptrlen(lem->paths) *
		sizeof(int))))
		failure(lem);
	while (i < ft_ptrlen(lem->paths))
	{
		if (get_str_before(lem->str, lem->paths[k] + 1 +
			ft_strichr(lem->paths[k], '-'), '-') && ft_strlen(lem->str))
		{
			while (lem->rooms[j] && ft_stristr_eq(lem->rooms[j], lem->str))
				++j;
		}
		else
		{
			while (lem->rooms[j] && ft_stristr_eq(lem->rooms[j], lem->paths[k]
				+ 1 + ft_strichr(lem->paths[k], '-')) == -1)
				++j;
		}
		lem->first_rooms[i] = j;
		++i;
		j = 0;
		++k;
	}
}

void	get_nb_paths(t_lem *lem)
{
	if (lem->pipes_start > lem->pipes_end)
		lem->nb_paths = lem->pipes_end;
	else
		lem->nb_paths = lem->pipes_start;
	if (!lem->nb_paths)
		error(lem);
}

void	init_rooms(t_lem *lem)
{
	int i;

	i = 0;
	if (!(lem->empty_rooms = (int *)malloc(lem->nb_rooms * sizeof(int))))
		failure(lem);
	while (i < lem->nb_rooms)
	{
		lem->empty_rooms[i] = 0;
		if (ft_stristr_eq(lem->rooms[i], lem->start) != -1)
			lem->empty_rooms[i] = lem->remain_ants;
		++i;
	}
}

void	init_ants(t_lem *lem)
{
	int i;

	i = 0;
	if (!(lem->ants = (int **)malloc(lem->nb_ants * sizeof(int*))))
		failure(lem);
	while (i < lem->nb_ants)
	{
		if (!(lem->ants[i] = (int *)malloc(4 * sizeof(int))))
			failure(lem);
		lem->ants[i][0] = lem->nb_start;
		lem->ants[i][1] = -1;
		lem->ants[i][2] = 0;
		lem->ants[i][3] = 0;
		++i;
	}
	lem->last_ant = 0;
	lem->remain_ants = lem->nb_ants;
}
