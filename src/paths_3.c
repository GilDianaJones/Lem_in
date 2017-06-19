/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 15:28:03 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/22 12:32:16 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char		*available_2(t_lem *lem, char *str, int j, int *avail_rooms)
{
	char	*tmp;
	int		k;

	tmp = str + 1 + ft_strichr_last(str, '-');
	k = 0;
	if (!ft_strcmp(get_str_before(lem->str, lem->pipes[j], '-'), tmp) &&
		ft_stristr(str, lem->pipes[j] + 1 + ft_strichr(lem->pipes[j], '-')))
	{
		while (ft_strcmp(lem->rooms[k], lem->pipes[j] + 1 +
			ft_strichr(lem->pipes[j], '-')))
			++k;
		if (!avail_rooms[k])
			return (lem->pipes[j] + 1 + ft_strichr(lem->pipes[j], '-'));
		k = 0;
	}
	if (!ft_strcmp(lem->pipes[j] + 1 + ft_strichr(lem->pipes[j], '-'),
		tmp) && ft_stristr(str, get_str_before(lem->str, lem->pipes[j], '-')))
	{
		while (ft_strcmp(lem->rooms[k], get_str_before(lem->str, lem->pipes[j],
			'-')))
			++k;
		if (!avail_rooms[k])
			return (get_str_before(lem->str, lem->pipes[j], '-'));
	}
	return (NULL);
}

char		*other_room(t_lem *lem, char *str, int j, int *avail_rooms)
{
	char	*tmp;

	tmp = str + ft_strichr_last(str, '-') + 1;
	while (lem->pipes[j])
	{
		if (!ft_strcmp(get_str_before(lem->str, lem->pipes[j], '-'), tmp) ||
			!ft_strcmp(lem->pipes[j] + 1 + ft_strichr(lem->pipes[j], '-'), tmp))
		{
			if (lem->pipes[j + 1])
				if (if_end(lem, j + 1, tmp))
					return (lem->end);
			if (available_2(lem, str, j, avail_rooms))
				return (available_2(lem, str, j, avail_rooms));
		}
		++j;
	}
	return (NULL);
}
