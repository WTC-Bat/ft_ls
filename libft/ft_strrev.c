/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:07:34 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/03 14:35:59 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *str)
{
	char	*revstring;
	int		cnt;
	int		len;

	cnt = 0;
	len = ft_strlen(str) - 1;
	revstring = (char *)malloc(sizeof(char) * len + 1);
	while (len != 0)
	{
		revstring[cnt] = str[len];
		len--;
		cnt++;
	}
	revstring[cnt++] = str[0];
	revstring[cnt] = '\0';
	return (revstring);
}
