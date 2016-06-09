/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:55:44 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/10 15:47:26 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!d || !s)
		return (0);
	if (d > s)
	{
		d += len;
		s += len;
		while (len-- != 0)
			*--d = *--s;
	}
	else
	{
		while (len-- != 0)
			*d++ = *s++;
	}
	return (dst);
}
