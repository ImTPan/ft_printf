/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 08:48:38 by tpan              #+#    #+#             */
/*   Updated: 2017/02/23 20:00:58 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	%[flags][width][.precision][length[specifier] legend
**	read from the va_list and ensure validity
*/

static int		read_conversion_substr(t_conversion *conversion,
		va_list ap, t_format *format)
{
	if (read_flags(conversion, format) == VALID
			&& read_width(conversion, ap, format) == VALID
			&& read_length(conversion, format) == VALID
			&& read_precision(conversion, ap, format) == VALID
			&& read_specifier(conversion, format) == VALID)
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

static void	print_var(t_format *format, va_list ap)
{
	t_conversion	conversion;

	if(double_percent(format))
		return ;
	if (read_conversion_substr(&conversion, ap, format) == VALID
		&& compatible_flags(&conversion, format) == VALID)
	{
		write_conversion_res()
		return ;
	}

}
