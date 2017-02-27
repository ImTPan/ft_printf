/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 16:07:51 by tpan              #+#    #+#             */
/*   Updated: 2017/02/26 19:19:09 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		apply_width_str(t_conversion *conversion, char **draft)
{
	char *temp;

	if(conversion->width > ft_strlen(*draft))
	{

	}
	return ;
}

static void		apply_width_int(t_conversion *conversion, char **draft)
{

}
