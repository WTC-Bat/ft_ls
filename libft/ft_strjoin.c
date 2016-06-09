/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:18:31 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 15:24:29 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	cnt;
	size_t	scnt;
	char	*str;
	size_t	len1;
	size_t	len2;

	cnt = 0;
	scnt = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 - 1));
	if (!str)
		return (0);
	while (scnt < len1)
		str[cnt++] = s1[scnt++];
	scnt = 0;
	while (scnt < len2)
		str[cnt++] = s2[scnt++];
	str[cnt] = '\0';
	return (str);
}
