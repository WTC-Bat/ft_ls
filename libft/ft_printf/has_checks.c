/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 13:28:24 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/05 13:23:12 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

int		haslength(char *fstr)
{
	int		len;

	len = ft_strlen(fstr) - 1;
	if (fstr[len - 1] == 'h' || fstr[len - 1] == 'l' ||
		fstr[len - 1] == 'j' || fstr[len - 1] == 'z')
		return (1);
	return (0);
}

int		hasprecision(char *fstr)
{
	if (ft_strchr(fstr, '.') == NULL)
		return (0);
	return (1);
}

int		haswidth(char *fstr)
{
	while (isprecision(*fstr) == 0 && islength(*fstr) == 0 &&
			istype(*fstr) == 0 && *fstr != '\0')
	{
		if (*fstr == '*' || ft_isdigit(*fstr))
			return (1);
		fstr++;
	}
	return (0);
}

int		hasflag(char *fstr)
{
	if (fstr[0] == '-' || fstr[0] == '+' || fstr[0] == ' ' ||
		fstr[0] == '#' || fstr[0] == '0')
	{
		return (1);
	}
	return (0);
}
