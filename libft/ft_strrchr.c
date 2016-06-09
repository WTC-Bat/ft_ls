/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:33:59 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/10 17:35:21 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	while (len != 0)
	{
		if (s[len] == c)
			return (&s[len]);
		len--;
	}
	return (NULL);
}
