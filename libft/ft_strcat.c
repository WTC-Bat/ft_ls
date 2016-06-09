/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:23:44 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/09 10:23:46 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int		cnt;
	int		len;

	cnt = 0;
	len = ft_strlen(dest);
	while (src[cnt])
	{
		dest[cnt + len] = src[cnt];
		cnt++;
	}
	dest[cnt + len] = '\0';
	return (dest);
}
