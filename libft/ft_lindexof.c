/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lindexof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 15:04:43 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/31 17:13:01 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lindexof(const char *str, int c)
{
	int		cnt;

	cnt = ft_strlen(str) - 1;
	while (cnt != 0)
	{
		if (str[cnt] == c)
			return (cnt);
		cnt--;
	}
	return (0);
}
