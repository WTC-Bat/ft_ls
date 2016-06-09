/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:16:03 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/03 13:38:26 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	malloc strs
*/

char	**ft_strsplit(char const *s, char c)
{
	char	**strs;
	size_t	scnt;
	size_t	strcnt;
	size_t	start;
	size_t	end;

	strs = NULL;
	scnt = 0;
	start = 0;
	end = 0;
	strcnt = 0;
	while (s[scnt])
	{
		if (s[scnt] == c)
		{
			if (s[scnt + 1] != c)
				start = scnt + 1;
			else if (s[scnt - 1] != c)
			{
				end = end - start;
				strs[strcnt] = ft_strsub(s, start, end);
			}
		}
		scnt++;
	}
	return (strs);
}
