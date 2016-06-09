/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 15:51:31 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/10 16:00:37 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t			cnt;
	unsigned char	*s_uc;

	cnt = 0;
	s_uc = (unsigned char *)s;
	while (cnt < n)
	{
		if (s_uc[cnt] == (unsigned char)c)
			return ((void *)&s_uc[cnt]);
		cnt++;
	}
	return (NULL);
}
