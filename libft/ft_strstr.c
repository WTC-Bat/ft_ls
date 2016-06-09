/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:08:29 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 15:08:34 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		cnt;
	int		cnt2;

	cnt = 0;
	cnt2 = 0;
	while (str[cnt])
	{
		while (str[cnt2 + cnt] == to_find[cnt2])
		{
			cnt2++;
			if (to_find[cnt2] == '\0')
				return (&str[cnt]);
		}
		cnt2 = 0;
		cnt++;
	}
	return (0);
}
