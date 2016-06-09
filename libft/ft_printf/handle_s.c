/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:49:29 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/02 16:53:22 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

char		*handle_s(va_list vlst, t_mods mods)
{
	int		fmtl_len;
	int		cnt;
	char	*out_str;
	wchar_t	*wcs;

	fmtl_len = ft_strlen(mods.fmtl);
	cnt = 0;
	if (fmtl_len > 1)
	{
		if (mods.fmtl[fmtl_len - 2] != 'l' || fmtl_len > 2)
			return ("ERROR: 's' can only make use of the 'l' modifier");
		wcs = va_arg(vlst, wchar_t *);
		out_str = (char *)malloc(sizeof(char) * ft_wcslen(wcs));
		while (*wcs != '\0')
		{
			out_str[cnt] = (char)*wcs;
			wcs++;
			cnt++;
		}
		out_str[cnt] = '\0';
	}
	else
		out_str = va_arg(vlst, char *);
	return (fmt_s(mods, out_str));
}
