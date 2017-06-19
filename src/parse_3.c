/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:08:46 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/23 07:51:20 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	get_nb_pipes(t_lem *lem, int i, int j)
{
	if (!(lem->nb_pipes = (int *)malloc(lem->nb_rooms * sizeof(int))))
		failure(lem);
	while (i < lem->nb_rooms)
		lem->nb_pipes[i++] = 0;
	i = 0;
	while (lem->pipes[i])
	{
		j = ft_stritabstr(lem->rooms, get_str_before(lem->str,
			lem->pipes[i], '-'));
		lem->nb_pipes[j] += 1;
		j = 0;
		while (ft_strcmp(lem->rooms[j], lem->pipes[i] + 1 +
				ft_strichr(lem->pipes[i], '-')))
			++j;
		lem->nb_pipes[j] += 1;
		++i;
		j = 0;
	}
	lem->pipes_start = lem->nb_pipes[lem->nb_start];
	lem->pipes_end = lem->nb_pipes[lem->nb_end];
}

int		parse_asso(t_lem *lem, int k)
{
	int i;
	int j;

	i = 0;
	j = k;
	k = 1;
	while (i < lem->nb_pipes_tot && k < lem->nb_pipes_tot)
	{
		while (k < lem->nb_pipes_tot)
		{
			if ((lem->asso[i][0] == lem->asso[k][0] ||
				lem->asso[i][0] == lem->asso[k][1]) &&
				(lem->asso[i][1] == lem->asso[k][0] ||
				(lem->asso[i][1] == lem->asso[k][1])))
			{
				lem->asso[i][0] = -1;
				lem->asso[i][1] = -1;
				--j;
			}
			++k;
		}
		++i;
		k = i + 1;
	}
	return (j);
}

int		get_asso(t_lem *lem, int i, int k)
{
	if (!(lem->asso = (int **)malloc((lem->nb_pipes_tot) * sizeof(int *))))
		failure(lem);
	while (lem->anthill[i])
	{
		if (ft_strichr(lem->anthill[i], '-') > 0 &&
			ft_strichr(lem->anthill[i], ' ') == -1 &&
			ft_strichr(lem->anthill[i], '#'))
		{
			if (!(lem->asso[k] = (int *)malloc(2 * sizeof(int))))
				failure(lem);
			lem->asso[k][0] = ft_stritabstr(lem->rooms, get_str_before(lem->str,
				lem->anthill[i], '-'));
			lem->asso[k][1] = ft_stritabstr(lem->rooms, lem->anthill[i] + 1 +
				ft_strichr(lem->anthill[i], '-'));
			if (lem->asso[k][0] == -1 || lem->asso[k][1] == -1)
				error(lem);
			++k;
		}
		++i;
	}
	return (parse_asso(lem, k));
}
