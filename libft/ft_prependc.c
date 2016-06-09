/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prependc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:14:19 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/31 17:14:20 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_prependc(char *str, int c)
{
	int		len;
	int		cnt;
	char	*out_str;

	len = ft_strlen(str) + 1;
	cnt = 1;
	out_str = (char *)malloc(sizeof(char) * len);
	out_str[0] = c;
	while (cnt < len)
	{
		out_str[cnt] = str[cnt - 1];
		cnt++;
	}
	out_str[len] = '\0';
	return (out_str);
}
