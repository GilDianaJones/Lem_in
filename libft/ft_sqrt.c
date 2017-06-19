/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:30:19 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/08 11:53:04 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_sqrt(int nb)
{
	int res;

	res = 1;
	while (res < nb / res)
		res++;
	if (res * res == nb)
		return (res);
	return (0);
}
