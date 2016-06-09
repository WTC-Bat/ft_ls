/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cap_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:49:42 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/05 13:13:07 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

char	*handle_cap_s(va_list vlst, t_mods mods)
{
	int		fmtl_len;
	int		cnt;
	char	*out_str;
	wchar_t	*wcs;

	fmtl_len = ft_strlen(mods.fmtl);
	cnt = 0;
	if (fmtl_len > 1)
		return ("ERROR: 'S' does not take any length modifier\n");
	wcs = va_arg(vlst, wchar_t *);
	out_str = (char *)malloc(sizeof(char) * ft_wcslen(wcs));
	while (*wcs != '\0')
	{
		out_str[cnt] = (char)*wcs;
		cnt++;
		wcs++;
	}
	out_str[cnt] = '\0';
	return (fmt_s(mods, out_str));
}
