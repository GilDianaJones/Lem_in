/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 09:24:05 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/25 12:15:38 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	get_pipes(t_lem *lem, int i, int j, int k)
{
	if (!(lem->pipes = (char **)malloc((j + 1) * sizeof(char *))))
		failure(lem);
	j = 0;
	while (lem->anthill[i])
	{
		if (ft_strichr(lem->anthill[i], '-') > 0 &&
			ft_strichr(lem->anthill[i], ' ') == -1 &&
			ft_strichr(lem->anthill[i], '#') == -1 &&
			ft_strichr(lem->anthill[i], 'L') && lem->asso[k][0] >= 0)
		{
			if (!(lem->pipes[j] = (char *)malloc(ft_strlen(lem->anthill[i])
				+ 1)) || !ft_strcpy(lem->pipes[j], lem->anthill[i]))
				failure(lem);
			++j;
		}
		else if (ft_strichr(lem->anthill[i], '-') > 0 &&
			ft_strichr(lem->anthill[i], ' ') == -1 &&
			ft_strichr(lem->anthill[i], '#') &&
			ft_strichr(lem->anthill[i], 'L') && lem->asso[k][0] < 0)
			++k;
		++i;
	}
	lem->pipes[j] = NULL;
}

int		*get_avail_rooms(t_lem *lem)
{
	int i;
	int j;
	int	*avail_rooms;

	i = 0;
	j = 0;
	if (lem->nb_rooms)
	{
		if (!(avail_rooms = (int *)malloc(lem->nb_rooms * sizeof(int))))
			failure(lem);
		while (i < lem->nb_rooms)
			avail_rooms[i++] = 0;
		return (avail_rooms);
	}
	return (NULL);
}

void	get_ind_start_end(t_lem *lem)
{
	int i;

	i = 0;
	while (lem->rooms[i] && ft_stristr_eq(lem->rooms[i], lem->start))
		++i;
	lem->nb_start = i;
	i = 0;
	while (lem->rooms[i] && ft_stristr_eq(lem->rooms[i], lem->end))
		++i;
	lem->nb_end = i;
}

void	get_rooms(t_lem *lem, int i, int j)
{
	if (!(lem->rooms = (char **)malloc((lem->nb_rooms + 1) * sizeof(char *))))
		failure(lem);
	while (lem->anthill[j])
	{
		if (ft_strichr(lem->anthill[j], '-') > 0 &&
			ft_strichr(lem->anthill[j], ' ') == -1)
			lem->nb_pipes_tot += 1;
		else if (ft_strichr(lem->anthill[j], ' ') > 0 &&
			(ft_strichr(lem->anthill[j], '-') == -1 ||
			ft_strichr(lem->anthill[j], '-') >
			ft_strichr(lem->anthill[j], ' ')) &&
			ft_strichr(lem->anthill[j], 'L') &&
			ft_strichr(lem->anthill[j], '#') == -1)
		{
			if (!(lem->rooms[i] = (char *)malloc(ft_strichr(lem->anthill[j],
				' ') + 1)) || !ft_strcpy(lem->rooms[i], get_str_before(lem->str,
				lem->anthill[j], ' ')))
				failure(lem);
			++i;
		}
		++j;
	}
	lem->rooms[i] = NULL;
}

void	get_coors(t_lem *lem, int i, int k)
{
	int l;

	l = 0;
	if (!(lem->coor = (char **)malloc((lem->nb_rooms + 1) * sizeof(char *))))
		failure(lem);
	while (lem->anthill[i])
	{
		if (ft_strichr(lem->anthill[i], ' ') > 0 &&
			ft_strichr(lem->anthill[i], '-') > 0 && ft_strichr(lem->anthill[i],
			'-') > ft_strichr(lem->anthill[i], ' '))
			error(lem);
		else if (ft_strichr(lem->anthill[i], ' ') > 0 &&
			ft_strichr(lem->anthill[i], '-') == -1 &&
			ft_strichr(lem->anthill[i], 'L') &&
			ft_strichr(lem->anthill[i], '#') == -1)
		{
			fill_coors(lem, 1 + ft_strichr(lem->anthill[i], ' '), i, k);
			++k;
			lem->coor[k] = NULL;
		}
		++i;
	}
}
