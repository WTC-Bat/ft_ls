/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 14:14:27 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/14 14:27:28 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_startswith(char *str, char *start)
{
	int		startlen;
	int		cnt;

	startlen = ft_strlen(start);
	cnt = 0;
	while (cnt < startlen)
	{
		if (str[cnt] != start[cnt])
			return (0);
		cnt++;
	}
	return (1);
}
