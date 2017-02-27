/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 10:32:13 by tpan              #+#    #+#             */
/*   Updated: 2017/02/27 10:48:31 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			apply_precision_str(t_conversion *conversion, char **draft)
{
	char	*temp;

	if (conversion->precision < ft_strlen(*draft))
	{
		temp = *draft;
		*draft = ft_strndup(*draft, conversion->precision);
		ft_memdel((void **)&temp);
	}
	return ;
}

static void			apply_precision_int(t_conversion *conversion, char **draft)
{
	char	*temp;
	int		i;

	if (ft_strlen(*draft) < conversion->precision)
	{
		temp = *draft;
		*draft = ft_strnew(conversion->precision);
		i = 0;
		while (conversion->precision > ft_strlen(temp) + i)
			(*draft)[i++] = '0';
		ft_strcpy(&((*draft)[i]), temp);
		ft_memdel((void **)&temp);
	}
	return ;
}

void				apply_precision_wstr(t_conversion *conversion,
															wchar_t **draft)
{
	wchar_t	*temp;

	if (conversion->precision < ft_wstrlen(*draft))
	{
		temp = *draft;
		*draft = ft_wstrndup(*draft, conversion->precision);
		ft_memdel((void **)&temp);
	}
	return ;
}

void				apply_precision(t_conversion *conversion, char **draft)
{
	if (conversion->specifier == STRING)
		apply_precision_str(conversion, draft);
	else if (conversion->specifier != POINTER)
		apply_precision_int(conversion, draft);
	return ;
}
