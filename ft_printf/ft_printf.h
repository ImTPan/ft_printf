/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 08:18:32 by tpan              #+#    #+#             */
/*   Updated: 2017/02/22 22:12:06 by tpan             ###   ########.fr       */
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
	FALSE, TRUE 
}				t_bool;

typedef struct		s_flags
{
	t_bool	hash;
	t_bool	pos_values_append_space;
	t_bool	show_sign;
	t_bool	left_justify;
	t_bool	pad_zeros;
}			t_flags;

typedef	struct		s_format
{
	const char	*str;
	size_t		index;
	size_t		chars_written;
}			t_format;

typedef enum		e_length
{
	DEFAULT, HH, H, L, LL, J, Z
}					t_length;

typedef enum		e_specifier
{
	S_DECIMAL, U_DECIMAL, OCTAL, HEX_LOWER, HEX_UPPER, CHAR, STRING, POINTER,
	INVALID_SPECIFIER
}					t_specifier;

typedef struct		s_conversion
{
	t_flags			flags;
	unsigned int	width;
	unsigned int	precision;
	t_bool			precision_set;
	t_length		length;
	t_specifier		specifier;
}			t_conversion;

int			read_flags(t_conversion *conversion, t_format *format);
int			read_length(t_conversion *conversion, t_format *format);
static int	read_precision(t_conversion *conversion, va_list ap,
				t_format *format);
static t_specifier compare_specifiers(char c);

#endif
