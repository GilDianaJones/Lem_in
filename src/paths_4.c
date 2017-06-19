/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 09:29:05 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/22 12:48:42 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		add_new_lst(t_list **paths, size_t k)
{
	t_list	*tmp;

	tmp = *paths;
	while (tmp && tmp->content_size != k)
		tmp = tmp->next;
	ft_lstaddend(paths, ft_lstnew(tmp->content, ft_strlen(tmp->content) + 1));
	tmp = *paths;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->content_size = ft_lstcnt(paths);
}

int			*get_paths_init(t_lem *lem, t_list **paths, int *avail_rooms,
	size_t k)
{
	int		j;
	int		*tmp_rooms;
	t_list	*tmp;

	j = 0;
	tmp = *paths;
	tmp_rooms = init_tmp_rooms(lem, avail_rooms);
	if (ft_lstcnt(paths) > 0)
		add_new_lst(paths, k);
	else
	{
		ft_lstaddend(paths, ft_lstnew((void *)lem->start,
			ft_strlen(lem->start) + 1));
		tmp = *paths;
		tmp->content_size = 1;
		(*paths) = tmp;
		lem->nb_pipes[lem->nb_start] -= 1;
		tmp_rooms[lem->nb_start] = 1;
	}
	return (tmp_rooms);
}

void		erase_tmp_room(int **tmp_rooms)
{
	if (*tmp_rooms)
	{
		free(*tmp_rooms);
		*tmp_rooms = NULL;
	}
}

void		fill_lst(t_lem *lem, t_list **temp, int j)
{
	char	*tmp;

	tmp = (*temp)->content;
	ft_realloc(&tmp, ft_strlen(lem->rooms[j]) + 2);
	ft_strconcat(&tmp, "-");
	ft_strconcat(&tmp, lem->rooms[j]);
	(*temp)->content = tmp;
}

void		get_paths(t_lem *lem, t_list **paths, int *avail_rooms, int k)
{
	int		j;
	char	*tmp;
	int		*tmp_rooms;
	t_list	*temp;
	t_list	*temp2;

	tmp_rooms = get_paths_init(lem, paths, avail_rooms, k);
	temp = *paths;
	while (temp)
	{
		if ((tmp = get_next_room(lem, temp->content, tmp_rooms)))
		{
			add_new_lst(paths, k + 1);
			temp2 = ft_lstend(paths);
			j = ft_stritabstr(lem->rooms, tmp);
			fill_lst(lem, &temp2, j);
			tmp_rooms[j] = 1;
			j = 0;
			if (!ft_strcmp(tmp, lem->end))
				break ;
		}
		else if ((temp = temp->next))
			++k;
	}
	erase_tmp_room(&tmp_rooms);
}
