/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:30:24 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/05 13:50:51 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

int		get_width(va_list vlst, char *fstr)
{
	char	width[5];
	int		cnt;

	cnt = 0;
	while (isprecision(*fstr) == 0 && islength(*fstr) == 0 &&
			istype(*fstr) == 0)
	{
		if (ft_isdigit(*fstr))
		{
			width[cnt] = *fstr;
			cnt++;
		}
		else if (*fstr == '*')
			return (va_arg(vlst, int));
		fstr++;
	}
	width[cnt] = '\0';
	return (ft_atoi(width));
}

int		get_precision(va_list vlst, char *fstr)
{
	int		cnt;
	char	prec[10];
	char	*prec_str;

	cnt = 0;
	prec_str = ft_strchr(fstr, '.');
	while (islength(*prec_str) == 0 && istype(*prec_str) == 0 &&
			prec_str[cnt] != '\0')
	{
		if (ft_isdigit(*prec_str))
		{
			prec[cnt] = *prec_str;
			cnt++;
		}
		else if (*prec_str == '*')
			return (va_arg(vlst, int));
		prec_str++;
	}
	prec[cnt] = '\0';
	return (ft_atoi(prec));
}
