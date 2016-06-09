/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 12:59:10 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/05 15:05:30 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

static char	*do_flags(char *out_str, t_mods mods)
{
	if (mods.flag == '+')
		out_str = ft_prependc(out_str, '+');
	else if (mods.flag == ' ')
		out_str = ft_prependc(out_str, ' ');
	return (out_str);
}

static char	*do_precision(char *new_str, char *pad, char *out_str, t_mods mods)
{
	int		cnt;
	int		slen;

	slen = ft_strlen(out_str);
	cnt = mods.precision - slen;
	if (mods.width < 0)
		ft_memset(pad, '0', (mods.precision - slen));
	else
	{
		ft_memset(pad, ' ', (mods.width - slen) - (mods.precision - slen));
		while (cnt > 0)
		{
			out_str = ft_prependc(out_str, '0');
			cnt--;
		}
	}
	if (mods.flag == '-')
		new_str = ft_strjoin(out_str, pad);
	else
		new_str = ft_strjoin(pad, out_str);
	new_str[ft_strlen(new_str)] = '\0';
	new_str = do_flags(new_str, mods);
	return (new_str);
}

static char	*do_width(char *new_str, char *pad, char *out_str, t_mods mods)
{
	int		slen;

	slen = ft_strlen(out_str);
	if (mods.flag == '+' || mods.flag == ' ')
	{
		if (mods.flag == '0')
			pad = ft_memset(pad, '0', (mods.width - slen - 1));
		else
			pad = ft_memset(pad, ' ', (mods.width - slen - 1));
		if (mods.flag == '+')
			out_str = ft_prependc(out_str, '+');
		else
			out_str = ft_prependc(out_str, ' ');
	}
	else
	{
		if (mods.flag == '0')
			pad = ft_memset(pad, '0', (mods.width - slen));
		else
			pad = ft_memset(pad, ' ', (mods.width - slen));
	}
	if (mods.flag == '-')
		return (new_str = ft_strjoin(out_str, pad));
	else
		return (new_str = ft_strjoin(pad, out_str));
}

char		*fmt_i(t_mods mods, char *out_str)
{
	char	*new_str;
	char	*pad;
	int		slen;

	slen = ft_strlen(out_str);
	if (mods.width != -1)
	{
		new_str = (char *)malloc(sizeof(char) * mods.width + 1);
		pad = (char *)malloc(sizeof(char) * (mods.width - slen));
		if (mods.precision != -1 && mods.precision > slen)
			new_str = do_precision(new_str, pad, out_str, mods);
		else if (mods.precision == -1)
			new_str = do_width(new_str, pad, out_str, mods);
	}
	else if (mods.precision > slen)
	{
		new_str = (char *)malloc(sizeof(char) * mods.precision);
		pad = (char *)malloc(sizeof(char) * (mods.precision - slen));
		new_str = do_precision(new_str, pad, out_str, mods);
	}
	else
		new_str = do_flags(out_str, mods);
	return (new_str);
}
