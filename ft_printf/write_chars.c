/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 12:20:05 by tpan              #+#    #+#             */
/*   Updated: 2017/02/25 19:31:21 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_chars(t_conversion *conversion, va_list ap,
						t_format *format)
{
	char	*draft;

	if (conversion->flags.hash)
		return ;
	draft = ft_strnew(1);

}
