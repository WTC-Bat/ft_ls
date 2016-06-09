/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 15:51:33 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/05 16:51:42 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

char	*handle_c(va_list vlst, t_mods mods)
{
	int		fmtl_len;
	char	out_char;
	wchar_t	wc;

	if (mods.precision != -1)
		return ("ERROR: 'c' cannot make use of precision\n");
	fmtl_len = ft_strlen(mods.fmtl);
	if (fmtl_len > 1 || mods.fmtl[fmtl_len] == 'C')
	{
		wc = va_arg(vlst, wchar_t);
		out_char = (char)wc;
	}
	else
		out_char = (char)va_arg(vlst, int);
	return (fmt_c(mods, out_char));
}
