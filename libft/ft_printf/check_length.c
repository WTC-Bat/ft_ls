/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 12:48:52 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/07 16:54:53 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

int	check_length(t_mods mods)
{
	int		len;
	int		cnt;

	len = ft_strlen(mods.fmtl);
	cnt = 0;
	while (cnt < len - 1)
	{
		if (mods.fmtl[cnt] != 'l' && mods.fmtl[cnt] != 'h' &&
			mods.fmtl[cnt] != 'j' && mods.fmtl[cnt] != 'z')
			return (0);
		cnt++;
	}
	return (1);
}
