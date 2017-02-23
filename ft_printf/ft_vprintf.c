/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 08:48:38 by tpan              #+#    #+#             */
/*   Updated: 2017/02/22 22:22:34 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	%[flags][width][.precision][length[specifier] legend
**	read from the va_list and ensure compatibility
*/

static int		read_conversion_substr(t_conversion *conversion,
		va_list ap, t_format *format)
{
	if (read_flags(conversion, format) == VALID
			&& read_width(conversion, ap, format) == VALID
			&& read_precision(conversion, ap, format) == VALID
			&& read_length(conversion, format) == VALID
			&& read_specifier(conversion, ap, format) == VALID)
		return (VALID);
	else
		return (INVALID);
}

static int		double_percent(t_format *format)
{
	if(format->str[format->index] == '%')
	{
		ft_putchar('%');
		format->index++;
		format->chars_written++;
		return (1);
	}
	return (0);
}
