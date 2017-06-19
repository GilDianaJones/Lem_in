/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:12:02 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/22 12:38:13 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		erase_lst(t_list **paths)
{
	t_list	*tmp;

	if (*paths)
	{
		tmp = (*paths);
		while (tmp)
			tmp = remove_lst(tmp);
		*paths = NULL;
	}
}

int			store_path(t_lem *lem, t_list **paths, int *temp_rooms, int j)
{
	int		k;
	int		l;
	t_list	*tmp;

	k = 1;
	l = 0;
	tmp = ft_lststrstr(paths, lem->end);
	lem->paths[j] = (char *)malloc(ft_strlen(tmp->content) + 1);
	if (!(ft_strcpy(lem->paths[j], tmp->content)))
		failure(lem);
	erase_lst(paths);
	while (k < ft_strichr_cnt(lem->paths[j], '-'))
	{
		l = ft_stritabstr(lem->rooms, get_str_before(lem->str, lem->paths[j] + 1
			+ ft_strichr_nb(lem->paths[j], '-', k), '-'));
		if (ft_strcmp(lem->rooms[l], lem->end))
			temp_rooms[l] = 1;
		l = 0;
		++k;
	}
	return (1);
}

int			store_rooms(t_lem *lem, t_list **paths, int *temp_rooms,
	t_list *temp)
{
	int		k;
	int		l;

	k = 0;
	l = 0;
	if (k < ft_strichr_cnt(temp->content, '-'))
	{
		while (k < ft_strichr_cnt(temp->content, '-'))
		{
			l = ft_stritabstr(lem->rooms, get_str_before(lem->str, temp->content
				+ 1 + ft_strichr_nb(temp->content, '-', k + 1), '-'));
			if (ft_strcmp(lem->rooms[l], lem->end))
				temp_rooms[l] = 1;
			++k;
		}
	}
	erase_lst(paths);
	return (1);
}

void		get_corrects_paths(t_lem *lem, t_list **paths, int *avail_rooms,
	int j)
{
	int		cnt;
	int		tmp_paths;
	int		*temp_rooms;
	t_list	*tmp;

	cnt = lem->nb_rooms;
	tmp_paths = lem->nb_paths;
	temp_rooms = init_tmp_rooms(lem, avail_rooms);
	erase_tmp_room(&avail_rooms);
	if (!(lem->paths = (char **)malloc((lem->nb_paths + 1) * sizeof(char *))))
		failure(lem);
	while (j < tmp_paths)
	{
		get_paths(lem, paths, temp_rooms, 0);
		tmp = ft_lststrstr(paths, lem->end);
		if (tmp && store_path(lem, paths, temp_rooms, j))
			++j;
		else if (tmp && store_rooms(lem, paths, temp_rooms, tmp))
			tmp_paths -= 1;
		else if (!tmp)
			error(lem);
	}
	lem->paths[j] = NULL;
	erase_lst(paths);
	erase_tmp_room(&temp_rooms);
}
