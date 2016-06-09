/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:02:41 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 15:12:11 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	int		cnt;
	int		cnt2;

	cnt = 0;
	cnt2 = 0;
	while (len != 0)
	{
		while (big[cnt2 + cnt] == little[cnt2])
		{
			cnt2++;
			if (little[cnt2] == '\0')
				return (&big[cnt]);
		}
		cnt2 = 0;
		cnt++;
		len--;
	}
	return (0);
}
