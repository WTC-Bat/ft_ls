/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:22:12 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/09 10:22:31 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t		cnt;

	cnt = 0;
	while (cnt < n)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		else if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
		cnt++;
	}
	return (0);
}
