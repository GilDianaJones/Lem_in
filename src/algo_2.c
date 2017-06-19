/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:58:06 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/22 16:23:56 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	print_space(t_lem *lem)
{
	if (lem->last_ant < lem->nb_ants)
	{
		if (lem->last_ant % lem->nb_paths)
			ft_putchar(' ');
	}
}

void	move_prev_ants(t_lem *lem, int j, int l)
{
	if (lem->ants[j][0] != lem->nb_end && !lem->ants[j][2])
	{
		if (lem->ants[j][3] + 1 <
			ft_strichr_cnt(lem->paths[lem->ants[j][1]], '-'))
			l = ft_stritabstr(lem->rooms, get_str_before(lem->str,
				lem->paths[lem->ants[j][1]] + 1 +
				ft_strichr_nb(lem->paths[lem->ants[j][1]], '-',
				lem->ants[j][3] + 1), '-'));
		else
			l = ft_stritabstr(lem->rooms, lem->end);
		if (!lem->empty_rooms[l] && ft_strcmp(lem->rooms[l], lem->end))
		{
			lem->empty_rooms[lem->ants[j][0]] -= 1;
			update_ants(lem, l, j);
			lem->empty_rooms[l] += 1;
			print_prev_space(lem, j);
		}
		else if (!ft_strcmp(lem->rooms[l], lem->end))
		{
			lem->empty_rooms[lem->ants[j][0]] -= 1;
			update_ants(lem, l, j);
			lem->remain_ants -= 1;
			lem->remain_ants ? ft_putchar(' ') : 0;
		}
	}
}

void	move_firsts_ants(t_lem *lem, int j, int l)
{
	if (lem->ants[lem->last_ant][1] == -1 && (!lem->empty_rooms[l] ||
		!ft_strcmp(lem->rooms[l], lem->end)))
	{
		lem->empty_rooms[lem->ants[lem->last_ant][0]] -= 1;
		lem->ants[lem->last_ant][1] = j;
		update_ants(lem, l, lem->last_ant);
		lem->empty_rooms[l] += 1;
		if (lem->last_ant < lem->nb_ants)
			lem->last_ant += 1;
		print_space(lem);
	}
	else if (lem->ants[lem->last_ant][1] >= 0 && (!lem->empty_rooms[l] ||
		!ft_strcmp(lem->rooms[l], lem->end)))
	{
		l = ft_stritabstr(lem->rooms, lem->rooms[
			lem->first_rooms[lem->ants[lem->last_ant][1]]]);
		lem->empty_rooms[lem->ants[lem->last_ant][0]] -= 1;
		update_ants(lem, l, lem->last_ant);
		lem->empty_rooms[l] += 1;
		if (lem->last_ant < lem->nb_ants)
			lem->last_ant += 1;
		lem->last_ant < lem->nb_paths ? ft_putchar(' ') : 0;
	}
	if (!ft_strcmp(lem->rooms[l], lem->end))
		lem->remain_ants -= 1;
}

int		first_ants(t_lem *lem, int *tmp_paths, int cnt)
{
	int j;
	int l;

	j = 0;
	if (lem->last_ant < lem->nb_ants && !lem->ants[lem->last_ant][2])
	{
		while (j < ft_ptrlen(lem->paths) && lem->last_ant < lem->nb_ants)
		{
			if (tmp_paths[j] < lem->nb_ants || tmp_paths[j] <=
				tmp_paths[lem->nb_paths] / lem->nb_paths)
			{
				l = ft_stritabstr(lem->rooms,
					lem->rooms[lem->first_rooms[j]]);
				move_firsts_ants(lem, j, l);
			}
			++j;
		}
		cnt = raz_ants(lem, cnt);
	}
	else if (lem->last_ant == lem->nb_ants && lem->remain_ants > 0)
		cnt = raz_ants(lem, cnt);
	return (cnt);
}

void	algo(t_lem *lem)
{
	int j;
	int cnt;
	int *tmp_paths;

	j = 0;
	cnt = 0;
	tmp_paths = init_tmp_paths(lem);
	init_ants_paths(lem, tmp_paths);
	while (lem->remain_ants > 0)
	{
		while (j < lem->last_ant)
		{
			move_prev_ants(lem, j, 0);
			++j;
		}
		j = 0;
		cnt = first_ants(lem, tmp_paths, cnt);
	}
	free(tmp_paths);
	tmp_paths = NULL;
}
