/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:05:21 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 15:05:23 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	cnt;
	size_t	start;
	size_t	end;

	start = 0;
	cnt = 0;
	end = ft_strlen(s) - 1;
	str = (char *)malloc(sizeof(char) * end);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	while (start <= end)
		str[cnt++] = s[start++];
	return (str);
}
