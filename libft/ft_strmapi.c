/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:08:52 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 15:09:11 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		cnt;

	if (!s || !f)
		return (0);
	str = (char *)malloc(sizeof(char *) * ft_strlen(s));
	cnt = 0;
	while (s[cnt])
	{
		str[cnt] = f(cnt, s[cnt]);
		cnt++;
	}
	return (str);
}
