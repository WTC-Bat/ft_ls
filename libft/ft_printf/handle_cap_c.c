/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cap_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:10:30 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/05 13:10:51 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

char	*handle_cap_c(va_list vlst, t_mods mods)
{
	int		fmtl_len;
	char	out_char;
	wchar_t	wc;

	if (mods.precision != -1)
		return ("ERROR: 'C' cannot make use of precision\n");
	fmtl_len = ft_strlen(mods.fmtl);
	if (fmtl_len > 1)
		return ("ERROR: 'C' does not take ant length modifier\n");
	wc = va_arg(vlst, wchar_t);
	out_char = (char)wc;
	return (fmt_c(mods, out_char));
}
