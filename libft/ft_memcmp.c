/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:24:41 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/10 17:17:28 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void *s1, void *s2, size_t n)
{
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;

	s1_uc = s1;
	s2_uc = s2;
	while (*s1_uc == *s2_uc)
	{
		if (n == 0)
			return (0);
		s1_uc++;
		s2_uc++;
		n--;
	}
	return (*s1_uc - *s2_uc);
}
