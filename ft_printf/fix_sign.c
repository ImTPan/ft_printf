/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:59:49 by tpan              #+#    #+#             */
/*   Updated: 2017/03/18 16:26:06 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		get_sign(t_conversion *conversion, char **draft)
{
    int			i;
    char		sign;
    
    i = 0;
    sign = '\0';
    while ((*draft)[i] != '\0')
    {
        if ((*draft)[i] == '-')
            sign = '-';
        else if ((*draft)[i] == '+')
            sign = '+';
        else if ((*draft)[i] == ' '
                 && conversion->flags.pos_values_append_space)
            sign = ' ';
        i++;
    }
    return (sign);
}

void			fix_sign_placement(t_conversion *conversion, char **draft)
{
    int			i;
    char		sign;
    
    i = 0;
    if ((sign = get_sign(conversion, draft)))
    {
        while ((*draft)[i] != '\0' && (*draft)[i] != '0')
            i++;
        (*draft)[i++] = sign;
        while ((*draft)[i] != '\0' && (*draft)[i] != sign)
            i++;
        (*draft)[i] = '0';
    }
}
