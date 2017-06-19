/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:34:56 by gthomas           #+#    #+#             */
/*   Updated: 2017/03/21 12:02:00 by gthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdarg.h>

void			d_parse_str(va_list ap, char *fmt, int i)
{
	if (fmt[i] == 's')
		ft_putstr((const char *)va_arg(ap, char *));
	else if (fmt[i] == 'c')
		ft_putchar(va_arg(ap, int));
}

void			d_parse_int(va_list ap, char *fmt, int i)
{
	if (fmt[i] == 'd')
		ft_putnbr(va_arg(ap, int));
}

void			d_parse_p(va_list ap, char *fmt, int i)
{
	if (fmt[i] == 'p')
	{
		ft_putstr("0x");
		ft_putnbr_hex(va_arg(ap, unsigned long int));
	}
}

void			ft_parsing(va_list ap, char *fmt)
{
	int i;

	i = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] && fmt[i] == '%')
		{
			++i;
			d_parse_str(ap, fmt, i);
			d_parse_int(ap, fmt, i);
			d_parse_p(ap, fmt, i);
		}
		else if (fmt[i] && fmt[i] != '\0' && fmt[i] != '%')
		{
			ft_putchar(fmt[i]);
		}
		++i;
	}
}

void			ft_lprintf(char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	ft_parsing(ap, fmt);
	va_end(ap);
}
