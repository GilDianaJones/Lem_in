/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:02:04 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/23 07:51:38 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		init_lem2(t_lem *lem)
{
	lem->anthill = NULL;
	lem->paths = NULL;
	lem->str = NULL;
	lem->tmp = NULL;
	lem->rooms = NULL;
	lem->pipes = NULL;
	lem->asso = NULL;
	lem->empty_rooms = NULL;
	lem->first_rooms = NULL;
	lem->start = NULL;
	lem->end = NULL;
	lem->nb_pipes = NULL;
	lem->ants = NULL;
	lem->last_room = NULL;
	lem->best_paths = NULL;
	lem->tmp_pipes = NULL;
	lem->ahill = NULL;
	lem->coor = NULL;
}

void		init_lem(t_lem *lem)
{
	lem->nb_paths = 0;
	lem->paths = 0;
	lem->last_ant = 0;
	lem->nb_pipes_tot = 0;
	lem->pipes_start = 0;
	lem->pipes_end = 0;
	lem->nb_start = 0;
	lem->nb_end = 0;
	lem->nb_ants = 0;
	lem->remain_ants = 0;
	init_lem2(lem);
}

void		init_max_room(t_lem *lem)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (lem->anthill[i])
	{
		if (ft_strichr(lem->anthill[i], ' ') > 0 &&
			ft_strichr(lem->anthill[i], '-') == -1 &&
			ft_strichr(lem->anthill[i], '#') == -1 &&
			ft_strichr(lem->anthill[i], 'L') != 0)
		{
			if (ft_strichr(lem->anthill[i], ' ') > j)
				j = i;
		}
		++i;
	}
	if (!(lem->str = (char *)malloc(j + 1)) ||
		!(lem->tmp = (char *)malloc(j + 1)))
		failure(lem);
	ft_bzero(lem->str, j + 1);
	ft_bzero(lem->tmp, j + 1);
}

void		get_infos(t_lem *lem, int i, int j, int n)
{
	char	*buf;

	if (!(lem->ahill = (char *)malloc(sizeof(char))))
		failure(lem);
	lem->ahill[0] = '\0';
	while (n == 1)
	{
		if (!(n = get_next_line(0, &buf)))
			break ;
		if (!ft_strlen(buf))
			break ;
		ft_realloc(&(lem->ahill), ft_strlen(buf));
		while (j < (int)ft_strlen(buf))
			lem->ahill[i++] = buf[j++];
		lem->ahill[i] = '\n';
		++i;
		free(buf);
		j = 0;
	}
	if (!lem->ahill || !lem->ahill[0])
		error(lem);
	lem->ahill[i] = '\0';
	if (buf)
		free(buf);
	parse(lem);
}

int			main(void)
{
	t_lem	*lem;

	if (!(lem = (t_lem *)malloc(sizeof(t_lem))))
		failure(lem);
	init_lem(lem);
	get_infos(lem, 0, 0, 1);
	erase(lem);
	return (0);
}
