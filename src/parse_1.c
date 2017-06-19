/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 10:52:36 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/25 11:52:35 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		get_nb_rooms(t_lem *lem)
{
	int		i;

	i = 0;
	lem->nb_rooms = 0;
	while (lem->anthill[i])
	{
		if (!ft_strichr(lem->anthill[i], '#') || ft_strichr(lem->anthill[i],
			'-') > 0 || !ft_strichr(lem->anthill[i], 'L'))
			++i;
		else if (ft_strichr(lem->anthill[i], ' ') > 0)
		{
			lem->nb_rooms += 1;
			++i;
		}
		else
			++i;
	}
}

void		get_end(t_lem *lem)
{
	int		i;

	i = 0;
	while (lem->anthill[i])
	{
		if (ft_stristr(lem->anthill[i], "##end") >= 0)
		{
			++i;
			if (ft_strichr(lem->anthill[i], ' ') == -1)
				error(lem);
			else
			{
				if (!(lem->end = (char *)malloc(ft_strichr(lem->anthill[i],
					' '))) || !(ft_strcpy(lem->end, get_str_before(lem->str,
					lem->anthill[i], ' '))))
					failure(lem);
				return ;
			}
		}
		++i;
	}
	error(lem);
}

void		get_start(t_lem *lem)
{
	int		i;

	i = 0;
	while (lem->anthill[i])
	{
		if (!ft_strcmp(lem->anthill[i], "##start"))
		{
			++i;
			if (lem->anthill[i] && ft_strichr(lem->anthill[i], ' ') > 0 &&
				lem->anthill[i][0] != 'L' && lem->anthill[i][0] != '#' &&
				lem->anthill[i][0] > ' ')
			{
				if (!(lem->start = (char *)malloc(ft_strichr(lem->anthill[i],
					' '))) || !(ft_strcpy(lem->start, get_str_before(lem->str,
					lem->anthill[i], ' '))))
					failure(lem);
				return ;
			}
			else
				error(lem);
		}
		++i;
	}
	error(lem);
}

void		get_nb_ants(t_lem *lem)
{
	int		i;

	i = 0;
	if (!ft_strisdigit(lem->anthill[0]) || !ft_strmaxint(lem->anthill[0]))
		error(lem);
	lem->nb_ants = ft_atoi(lem->anthill[0]);
	if (lem->nb_ants <= 0)
		error(lem);
}

void		parse(t_lem *lem)
{
	t_list	*paths;

	paths = NULL;
	if (!(lem->anthill = ft_strsplit(lem->ahill, '\n')))
		failure(lem);
	init_max_room(lem);
	get_nb_ants(lem);
	get_start(lem);
	get_end(lem);
	get_nb_rooms(lem);
	get_coors(lem, 0, 0);
	get_rooms(lem, 0, 0);
	get_ind_start_end(lem);
	get_pipes(lem, 0, get_asso(lem, 0, 0), 0);
	get_nb_pipes(lem, 0, 0);
	get_nb_paths(lem);
	get_corrects_paths(lem, &paths, get_avail_rooms(lem), 0);
	init_ants(lem);
	init_rooms(lem);
	get_first_rooms(lem, 0, 0, 0);
	ft_putendl(lem->ahill);
	algo(lem);
}
