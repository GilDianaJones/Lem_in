/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:02:04 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/25 12:10:32 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	fill_coors(t_lem *lem, int j, int i, int k)
{
	int l;

	l = 0;
	while (lem->anthill[i][j] != '\0')
	{
		if (!ft_isdigit(lem->anthill[i][j]) &&
			lem->anthill[i][j] != ' ')
			error(lem);
		++j;
	}
	j = 1 + ft_strichr(lem->anthill[i], ' ');
	if (ft_strichr_cnt(lem->anthill[i], ' ') != 2 ||
			!ft_strisdigit(lem->anthill[i] + j + 1 +
			ft_strichr(lem->anthill[i] + j, ' ')) ||
			!ft_strmaxint(lem->anthill[i] + j) ||
			!ft_strmaxint(lem->anthill[i] + j + 1 +
			ft_strichr(lem->anthill[i] + j, ' ')))
		error(lem);
	if (!(lem->coor[k] = (char *)malloc(ft_strlen(lem->anthill[i] + j)
		+ 1)) || !ft_strcpy(lem->coor[k], lem->anthill[i] + j))
		failure(lem);
	while (l < k)
		if (!strcmp(lem->coor[l++], lem->coor[k]))
			error(lem);
}

void	error(t_lem *lem)
{
	ft_putendl("ERROR");
	erase(lem);
	exit(EXIT_FAILURE);
}

void	failure(t_lem *lem)
{
	erase(lem);
	exit(EXIT_FAILURE);
}

void	print_res(int val, char *str)
{
	ft_putchar('L');
	ft_putnbr(val);
	ft_putchar('-');
	ft_putstr(str);
}
