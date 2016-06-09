/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 12:20:55 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/09 12:40:10 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*out_str;
	int		cnt;

	out_str = (char *)malloc(sizeof(char *) * ft_strlen(str));
	cnt = 0;
	while (str[cnt])
	{
		out_str[cnt] = str[cnt];
		cnt++;
	}
	out_str[cnt] = '\0';
	return (out_str);
}
