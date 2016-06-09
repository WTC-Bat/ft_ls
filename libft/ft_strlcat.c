/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:14:47 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/31 17:16:58 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	cnt;
	size_t	dlen;
	char	*d;
	char	*s;

	cnt = 0;
	dlen = 0;
	d = dst;
	s = src;
	while (dst[cnt] && cnt < size)
		cnt++;
	dlen = cnt;
	while (s[cnt - dlen] && cnt < size)
	{
		d[cnt] = s[cnt - dlen];
		cnt++;
	}
	if (dlen < size)
		d[cnt] = '\0';
	return (dlen + ft_strlen(src));
}
