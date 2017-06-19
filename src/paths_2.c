/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 14:07:46 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/22 12:32:33 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char		*if_end(t_lem *lem, int k, char *str)
{
	while (lem->pipes[k])
	{
		if ((!ft_strcmp(get_str_before(lem->str, lem->pipes[k], '-'), str) ||
			!ft_strcmp(lem->pipes[k] + 1 + ft_strichr(lem->pipes[k],
			'-'), str)) && (!ft_strcmp(get_str_before(lem->tmp, lem->pipes[k],
			'-'), lem->end) || !ft_strcmp(lem->pipes[k] + 1 +
			ft_strichr(lem->pipes[k], '-'), lem->end)))
			return (lem->end);
		++k;
	}
	return (NULL);
}

char		*available_1(t_lem *lem, char *str, int j, int *avail_rooms)
{
	int		k;

	k = 0;
	if (!ft_stristr_eq(get_str_before(lem->str, lem->pipes[j], '-'), str)
		&& ft_stristr(str, lem->pipes[j] + 1 +
		ft_strichr(lem->pipes[j], '-')) == -1)
	{
		while (ft_strcmp(lem->rooms[k], lem->pipes[j] + 1 +
			ft_strichr(lem->pipes[j], '-')))
			++k;
		if (!avail_rooms[k])
			return (lem->pipes[j] + 1 + ft_strichr(lem->pipes[j], '-'));
		k = 0;
	}
	if (!ft_stristr_eq(lem->pipes[j] + 1 + ft_strichr(lem->pipes[j], '-'), str)
		&& ft_stristr(str, get_str_before(lem->str, lem->pipes[j], '-')) == -1)
	{
		while (ft_strcmp(lem->rooms[k], get_str_before(lem->str, lem->pipes[j],
			'-')))
			++k;
		if (!avail_rooms[k])
			return (get_str_before(lem->str, lem->pipes[j], '-'));
	}
	return (NULL);
}

char		*first_room(t_lem *lem, char *str, int j, int *avail_rooms)
{
	while (lem->pipes[j])
	{
		if (ft_strichr(lem->pipes[j], '-') > 0 &&
			ft_strichr(lem->pipes[j], '#') == -1)
		{
			if (ft_stristr(lem->pipes[j], str) >= 0)
			{
				if (lem->pipes[j + 1])
				{
					if (if_end(lem, j + 1, str))
						return (lem->end);
				}
				if (available_1(lem, str, j, avail_rooms))
					return (available_1(lem, str, j, avail_rooms));
			}
		}
		++j;
	}
	return (NULL);
}

char		*get_next_room(t_lem *lem, char *str, int *avail_rooms)
{
	int		i;

	i = ft_strichr_cnt(str, '-');
	if (i == 0)
		return (first_room(lem, str, 0, avail_rooms));
	else
		return (other_room(lem, str, 0, avail_rooms));
	return (NULL);
}
