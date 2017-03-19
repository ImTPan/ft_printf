/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:07:06 by tpan              #+#    #+#             */
/*   Updated: 2017/03/18 18:44:46 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		read_width(t_conversion *conversion, va_list ap, 
		t_format *format)
{
	int holder;
/*
** If the asterisk is given then the precision is not given in the format
** string and is given as an int value instead.
*/
	if(format->str[format->index] == '*')
	{
		holder = va_arg(ap, int);
		if(holder < 0)
		{
			holder = -holder;
			conversion->flags.left_justify =1;
		}
		conversion->width = holder;
		format->index++;
	}
	else if (ft_isdigit(format->str[format->index]))
	{
		conversion->width = ft_atoi(&format->str[format->index]);
		while (ft_isdigit(format->str[format->index]))
			format->index++;
	}
	return(VALID);
}
