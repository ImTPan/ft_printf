/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 08:18:32 by tpan              #+#    #+#             */
/*   Updated: 2017/02/01 14:54:33 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <wchar.h>

# define INVALID	1
# define VALID		0

typedef enum	e_bool
{
	FALSE,TRUE 
}				t_bool;

typedef struct		s_flags
{
	t_bool	hash;
	t_bool	pos_values_append_space;
	t_bool	show_sign;
	t_bool	left_justify;
	t_bool	pad_zeros;
}					t_flags;



#endif
