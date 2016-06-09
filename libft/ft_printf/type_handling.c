/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:57:09 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/06 12:38:45 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

static char	*handle_type_2(va_list vlst, t_mods mods, char *out_str)
{
	int		len;

	len = ft_strlen(mods.fmtl) - 1;
	if (mods.fmtl[len] == 'u' || mods.fmtl[len] == 'U')
		out_str = handle_u(vlst, mods);
	else if (mods.fmtl[len] == 'o' || mods.fmtl[len] == 'O')
		out_str = handle_o(vlst, mods);
	else if (mods.fmtl[len] == 'x' || mods.fmtl[len] == 'X')
		out_str = handle_x(vlst, mods);
	return (out_str);
}

char		*handle_type_1(va_list vlst, t_mods mods)
{
	int		len;
	char	*out_str;

	out_str = NULL;
	len = ft_strlen(mods.fmtl) - 1;
	if (mods.fmtl[len] == 's')
		out_str = handle_s(vlst, mods);
	else if (mods.fmtl[len] == 'S')
		out_str = handle_cap_s(vlst, mods);
	else if (mods.fmtl[len] == 'p')
		out_str = handle_p(vlst, mods);
	else if (mods.fmtl[len] == 'c')
		out_str = handle_c(vlst, mods);
	else if (mods.fmtl[len] == 'C')
		out_str = handle_cap_c(vlst, mods);
	else if (mods.fmtl[len] == 'i' || mods.fmtl[len] == 'd' ||
				mods.fmtl[len] == 'D')
		out_str = handle_i(vlst, mods);
	else
		out_str = handle_type_2(vlst, mods, out_str);
	return (out_str);
}
