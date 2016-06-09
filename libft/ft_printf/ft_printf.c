/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:57:58 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/05 18:17:46 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

static char	*fstr_build(char *format)
{
	char	*fstr;
	int		cnt;

	fstr = (char *)malloc(sizeof(char) * 10);
	cnt = 0;
	while (istype(format[cnt]) == 0)
	{
		fstr[cnt] = format[cnt];
		cnt++;
	}
	fstr[cnt] = format[cnt];
	fstr[cnt + 1] = '\0';
	return (fstr);
}

static char	*get_fmtl(char *fstr)
{
	int		len;
	int		fmtlsz;
	int		cnt;
	char	*fmtl;

	len = ft_strlen(fstr) - 1;
	fmtlsz = 0;
	cnt = 0;
	while (isprecision(fstr[len]) == 0 && iswidth(fstr) == 0 &&
			isflag(fstr[len]) == 0 && len-- > 0)
		fmtlsz++;
	len = ft_strlen(fstr) - 1;
	fmtl = (char *)malloc(sizeof(char) * fmtlsz + 1);
	if (istype(fstr[len]) == 1)
	{
		if (islength(fstr[len - 1]) == 1)
		{
			if (islength(fstr[len - 2]) == 1)
				fmtl[cnt++] = fstr[len - 2];
			fmtl[cnt++] = fstr[len - 1];
		}
		fmtl[cnt++] = fstr[len];
		fmtl[cnt] = '\0';
	}
	return (fmtl);
}

static char	*arg_build(va_list vlst, char *fstr, int *pcnt)
{
	char	*out;
	t_mods	mods;

	mods.width = -1;
	mods.precision = -1;
	mods.flag = '\0';
	if (haswidth(fstr) == 1)
		mods.width = get_width(vlst, fstr);
	if (hasprecision(fstr) == 1)
		mods.precision = get_precision(vlst, fstr);
	if (hasflag(fstr) == 1)
		mods.flag = fstr[0];
	mods.fmtl = get_fmtl(fstr);
	out = handle_type_1(vlst, mods);
	*pcnt += ft_strlen(out);
	return (out);
}

int			ft_printf(char *format, ...)
{
	va_list	vlst;
	int		cnt;

	va_start(vlst, format);
	cnt = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				ft_putchar('%');
			else
			{
				ft_putstr(arg_build(vlst, fstr_build(format), &cnt));
				format += ft_strlen(fstr_build(format)) - 1;
			}
		}
		else
			ft_putchar(*format);
		format++;
		cnt++;
	}
	va_end(vlst);
	return (cnt);
}
