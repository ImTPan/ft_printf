#include "ft_printf.h"

static int		treat_negative_precision_as_none(t_conversion *conversion,
												t_format *format)
{
	conversion->precision = 0;
	format->index++;
	while (ft_isdigit(format->str[format->index]))
		format->index++;
	return (GOOD);
}

/*
** This function will look for a precision value in the format string and store
** it if present.
*/

int				read_precision(t_conversion *conversion, va_list ap,
												t_format *format)
{
	if (format->str[format->index] == '.')
	{
		format->index++;
		if (format->str[format->index] == '-')
			return (treat_negative_precision_as_none(conversion, format));
		if (format->str[format->index] == '*')
		{
			conversion->precision = va_arg(ap, unsigned int);
			conversion->precision_set = 1;
			format->index++;
			return (GOOD);
		}
		if (ft_isdigit(format->str[format->index]))
		{
			conversion->precision = ft_atoi(&format->str[format->index]);
			conversion->precision_set = 1;
			while (ft_isdigit(format->str[format->index]))
				format->index++;
			return (GOOD);
		}
		return (ERROR); // I'm not sure if this should ERROR or ignore/continue
	}
	return (GOOD);
}