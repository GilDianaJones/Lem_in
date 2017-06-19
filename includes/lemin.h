/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:04:36 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/22 17:40:52 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct	s_lem
{
	char		*ahill;
	char		**anthill;
	char		**paths;
	char		*str;
	char		*tmp;
	char		**rooms;
	char		**pipes;
	int			**asso;
	int			*empty_rooms;
	int			nb_ants;
	int			remain_ants;
	int			*first_rooms;
	char		*start;
	int			nb_start;
	int			pipes_start;
	char		*end;
	int			nb_end;
	int			pipes_end;
	int			nb_rooms;
	int			*nb_pipes;
	int			*tmp_pipes;
	int			nb_pipes_tot;
	int			**ants;
	int			last_ant;
	int			path;
	int			nb_paths;
	int			*last_room;
	int			**best_paths;
	char		**coor;
}				t_lem;

void			error(t_lem *lem);
void			erase(t_lem *lem);
void			failure(t_lem *lem);
void			print_res(int val, char *str);
void			get_nb_rooms(t_lem *lem);
void			get_end(t_lem *lem);
void			get_start(t_lem *lem);
void			get_nb_ants(t_lem *lem);
void			parse(t_lem *lem);
void			get_pipes(t_lem *lem, int i, int j, int k);
int				*get_avail_rooms(t_lem *lem);
void			get_ind_start_end(t_lem *lem);
void			get_rooms(t_lem *lem, int i, int j);
void			get_nb_pipes(t_lem *lem, int i, int j);
int				get_asso(t_lem *lem, int i, int k);
void			get_first_rooms(t_lem *lem, int i, int j, int k);
void			init_rooms(t_lem *lem);
void			init_ants(t_lem *lem);
void			algo(t_lem *lem);
void			select_paths(t_lem *lem, int i, int j, int l);
void			parse_paths(t_lem *lem, int i, int j, t_list **paths);
void			ft_realloc_starstar(t_lem *lem, int size);
char			*get_next_room(t_lem *lem, char *str, int *avail_rooms);
void			get_paths(t_lem *lem, t_list **paths, int *avail_rooms, int k);
void			get_nb_paths(t_lem *lem);
char			*available_2(t_lem *lem, char *str, int j, int *avail_rooms);
char			*other_room(t_lem *lem, char *str, int j, int *avail_rooms);
char			*if_end(t_lem *lem, int k, char *str);
void			init_max_room(t_lem *lem);
void			init_lem(t_lem *lem);
void			get_corrects_paths(t_lem *lem, t_list **paths, int *avail_rooms,
	int j);
int				*init_tmp_rooms(t_lem *lem, int *avail_rooms);
t_list			*remove_lst(t_list *tmp);
void			add_new_lst(t_list **paths, size_t k);
int				*get_paths_init(t_lem *lem, t_list **paths, int *avail_rooms,
	size_t k);
void			erase_tmp_room(int **tmp_rooms);
void			fill_lst(t_lem *lem, t_list **temp, int j);
void			init_tmp_pipes(t_lem *lem);
void			paths_selected(t_lem *lem, char **tmp, int i);
void			update_ants(t_lem *lem, int l, int j);
void			print_laps(int cnt);
int				raz_ants(t_lem *lem, int cnt);
int				*init_tmp_paths(t_lem *lem);
void			init_ants_paths(t_lem *lem, int *tmp_paths);
void			move_prev_ants(t_lem *lem, int j, int l);
void			move_firsts_ants(t_lem *lem, int j, int l);
int				first_ants(t_lem *lem, int *tmp_paths, int cnt);
void			erase_lst(t_list **paths);
void			get_coors(t_lem *lem, int i, int k);
void			print_prev_space(t_lem *lem, int j);
void			fill_coors(t_lem *lem, int j, int i, int k);

#endif
