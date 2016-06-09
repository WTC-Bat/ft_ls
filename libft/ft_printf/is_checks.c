/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:28:40 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/05 13:23:37 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

int		istype(int c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' ||
		c == 'D' || c == 'i' || c == 'o' || c == 'O' ||
		c == 'u' || c == 'U' || c == 'x' || c == 'X' ||
		c == 'c' || c == 'C')
		return (1);
	return (0);
}

int		islength(int c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}

int		isprecision(int c)
{
	if (c == '.')
		return (1);
	return (0);
}

int		iswidth(char *fstr)
{
	int		cnt;

	cnt = 0;
	while (isprecision(fstr[cnt]) == 0 && islength(fstr[cnt]) == 0 &&
			istype(fstr[cnt]) == 0 && fstr[cnt] != '\0')
	{
		if (fstr[cnt] == '*' || ft_isdigit(fstr[cnt]) == 1)
		{
			if (ft_strchr(fstr, '.') == NULL)
				return (1);
			else if (ft_indexof(fstr, '.') > cnt)
				return (1);
			else
				return (0);
		}
		cnt++;
	}
	return (0);
}

int		isflag(int c)
{
	if (c == '-' || c == '+' || c == ' ' ||
		c == '#' || c == '0')
		return (1);
	return (0);
}
