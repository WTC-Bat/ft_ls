/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:14:10 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 15:14:16 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;

	if (!s || !f)
		return (0);
	str = (char *)malloc(sizeof(char *) * ft_strlen(s));
	while (*s)
		*str++ = f(*s);
	return (str);
}
