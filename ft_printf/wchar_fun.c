/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:53:25 by tpan              #+#    #+#             */
/*   Updated: 2017/02/27 23:09:58 by tpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wstrlen(wchar_t const *str)
{
	size_t len;
	
	while (str[len])
	{
		len++;
	}
	return (len);
}

wchar_t		*ft_wstrndup(const char *s1, size_t n)
{
	wchar_t			*str;
	wchar_t			*p;
	unsigned long	i;

	i = 0;
	if ((size_t)ft_strlen((char *)s1)<n)
		str = (wchar_t *)malloc(sizeof(char) * ft_strlen((char *)s1)+1);
	else
		str = (wchar_t *)malloc(sizeof(char) * (n + 1));
	if(str && n)
	{
		p = str;
		while (*s1 && n > 1)
		{
			*p++ = *s1++;
			n--;
		}
		*p = '\0';
		return (str);
	}
	return (NULL);
}


