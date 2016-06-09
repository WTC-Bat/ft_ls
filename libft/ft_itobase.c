/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 14:41:32 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/03 14:43:00 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itobase(int n, int base)
{
    char	basechars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char	*tmp;
	char	*baseout;
    int		rem;
	int		cnt;
    int		i;
    
    rem = n;
	cnt = 0;
	i = 0;
    tmp = (char *)malloc(sizeof(char) * 64);
	baseout = (char *)malloc(sizeof(tmp));
    while (rem > 0)
    {
        i = rem % base;
        rem = rem / base;
		tmp[cnt] = basechars[i];
		cnt++;
    }
	baseout = ft_strrev(tmp);
	baseout[cnt] = '\0';
	return (baseout);
}
