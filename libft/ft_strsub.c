/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:13:26 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 15:13:28 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	cnt;
	char	*sub;

	cnt = 0;
	sub = (char *)malloc(sizeof(char) * len);
	if (!sub)
		return (0);
	while (cnt < len)
	{
		sub[cnt] = s[start + cnt];
		cnt++;
	}
	sub[cnt] = '\0';
	return (sub);
}
