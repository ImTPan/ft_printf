/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_wchar_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <tpan@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 21:05:12 by tpan              #+#    #+#             */
/*   Updated: 2017/02/27 22:03:49 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static void			apply_width_wstr(t_conversion *conversion, wchar_t **draft)
{
    wchar_t		*temp;
    
    if (conversion->width > ft_wstrlen(*draft))
    {
        temp = *draft;
        *draft = (wchar_t *)ft_strnew(conversion->width * sizeof(wchar_t) + 3);
        if (conversion->flags.left_justify)
        {
            ft_wstrcpy(*draft, temp);
            ft_wchar_memset(&(*draft)[ft_wstrlen(temp)], ' ',
                            conversion->width - ft_wstrlen(temp));
        }
        else
        {
            ft_wchar_memset(*draft, ' ', conversion->width - ft_wstrlen(temp));
            ft_wstrcpy(&(*draft)[conversion->width - ft_wstrlen(temp)], temp);
        }
        ft_memdel((void **)&temp);
    }
    return ;
}

static void			apply_width_wint(t_conversion *conversion, wchar_t **draft)
{
    wchar_t		*temp;
    
    if (ft_wstrlen(*draft) < conversion->width)
    {
        temp = *draft;
        *draft = (wchar_t *)ft_strnew(conversion->width * sizeof(wchar_t) + 3);
        if (conversion->flags.left_justify)
        {
            ft_wstrcpy(*draft, temp);
            ft_wchar_memset(&(*draft)[ft_wstrlen(*draft)], ' ',
                            conversion->width - ft_wstrlen(*draft));
        }
        else
        {
            ft_wchar_memset(*draft,
                            (conversion->flags.pad_zeros ? '0' : ' '),
                            conversion->width - ft_wstrlen(temp));
            ft_wstrcpy(&(*draft)[conversion->width - ft_wstrlen(temp)], temp);
        }
        ft_memdel((void **)&temp);
    }
}

void				apply_width_wchar(t_conversion *conversion, wchar_t **draft)
{
    if (conversion->specifier == STRING)
        apply_width_wstr(conversion, draft);
    else
        apply_width_wint(conversion, draft);
    return ;
}
