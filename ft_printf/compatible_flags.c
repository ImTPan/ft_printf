/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compatible_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:01:33 by tpan              #+#    #+#             */
/*   Updated: 2017/02/23 20:47:29 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static void			pos_values_append_space_corr(t_conversion *conversion)
{
	if (conversion->flags.pos_values_append_space 
			&& conversion->flags.show_sign)
		conversion->flags.pos_values_append_space = INVALID;
	return ;
}

static void			pad_zeros_corr(t_conversion *conversion)
{
	if (conversion->flags.pad_zeros)
		if(conversion->flags.left_justify || conversion->precision_set)
				conversion->flags.pad_zeros = 0;
	return ;
}
