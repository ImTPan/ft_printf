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

int				ft_vprintf(const char *format, va_list ap)
{
    t_format	format_tracker;
    
    if (!format)
        return (0);
    ft_bzero(&format_tracker, sizeof(t_format));
    format_tracker.str = format;
    while (format_tracker.str[format_tracker.index] != '\0')
    {
        if (format_tracker.str[format_tracker.index] == '%')
        {
            format_tracker.index++;
            print_var(&format_tracker, ap);
        }
        else
        {
            ft_putchar(format_tracker.str[format_tracker.index++]);
            format_tracker.chars_written++;
        }
    }
    return (format_tracker.chars_written);
}
