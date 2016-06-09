/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:16:09 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/05 15:59:22 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

static char	*do_precision(char *new_str, char *pad, char *out_str, t_mods mods)
{
	int		cnt;
	int		slen;

	slen = ft_strlen(out_str);
	cnt = mods.precision - slen;
	if (mods.flag == ' ' || mods.flag == '+')
		return ("ERROR: unsupported flag for 'x'");
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
	return (new_str);
}

static char	*do_width(char *new_str, char *pad, char *out_str, t_mods mods)
{
	int		slen;

	slen = ft_strlen(out_str);
	if (mods.flag == ' ' || mods.flag == '+')
		return ("ERROR: unsupported flag for 'x'");
	if (mods.flag == '0')
		pad = ft_memset(pad, '0', (mods.width - slen));
	else
		pad = ft_memset(pad, ' ', (mods.width - slen));
	if (mods.flag == '#')
	{
		if (mods.fmtl[ft_strlen(mods.fmtl - 1)] == 'X')
			out_str = ft_prependc(out_str, 'X');
		else
			out_str = ft_prependc(out_str, 'x');
		out_str = ft_prependc(out_str, '0');
	}
	if (mods.flag == '-')
		new_str = ft_strjoin(out_str, pad);
	else
		new_str = ft_strjoin(pad, out_str);
	return (new_str);
}

static char	*do_flags(t_mods mods, char *out_str)
{
	char	*ret_str;

	ret_str = (char *)malloc(sizeof(char) * (ft_strlen(out_str) + 1));
	if (mods.flag == ' ' || mods.flag == '+')
		return ("ERROR: unsupported flag for 'x'");
	if (mods.flag == '#')
	{
		if (mods.fmtl[ft_strlen(mods.fmtl - 1)] == 'X')
			ret_str = ft_prependc(out_str, 'X');
		else
			ret_str = ft_prependc(out_str, 'x');
		ret_str = ft_prependc(ret_str, '0');
	}
	else
		ret_str = out_str;
	ret_str[ft_strlen(out_str) + 2] = '\0';
	return (ret_str);
}

char		*fmt_x(t_mods mods, char *out_str)
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
		new_str = out_str;
	if (mods.flag == '#')
		new_str = do_flags(mods, new_str);
	return (new_str);
}
