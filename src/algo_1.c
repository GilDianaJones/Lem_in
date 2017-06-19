/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:52:02 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/22 15:59:20 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	print_prev_space(t_lem *lem, int j)
{
	if (lem->last_ant < lem->nb_ants)
		j < lem->last_ant ? ft_putchar(' ') : 0;
	else
		j < lem->last_ant - 1 ? ft_putchar(' ') : 0;
}

void	update_ants(t_lem *lem, int l, int j)
{
	lem->ants[j][0] = l;
	lem->ants[j][2] = 1;
	lem->ants[j][3] += 1;
	print_res(j + 1, lem->rooms[l]);
}

int		raz_ants(t_lem *lem, int cnt)
{
	int l;

	l = 0;
	ft_putchar('\n');
	cnt += 1;
	while (l < lem->last_ant)
	{
		lem->ants[l][2] = 0;
		++l;
	}
	return (cnt);
}

int		*init_tmp_paths(t_lem *lem)
{
	int i;
	int	*tmp_paths;

	i = 0;
	tmp_paths = (int *)malloc((lem->nb_paths + 1) * sizeof(int));
	tmp_paths[lem->nb_paths] = 0;
	while (i < lem->nb_paths)
	{
		tmp_paths[i] = ft_strichr_cnt(lem->paths[i], '-');
		tmp_paths[lem->nb_paths] += tmp_paths[i];
		++i;
	}
	return (tmp_paths);
}

void	init_ants_paths(t_lem *lem, int *tmp_paths)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (lem->empty_rooms[lem->nb_start] == lem->nb_ants)
	{
		while (i < ft_ptrlen(lem->paths) && i < lem->nb_ants)
		{
			if (tmp_paths[i] <= tmp_paths[lem->nb_paths] / lem->nb_paths || (
				lem->nb_ants > tmp_paths[i]))
			{
				lem->ants[j][1] = i;
				++j;
			}
			++i;
		}
	}
}
