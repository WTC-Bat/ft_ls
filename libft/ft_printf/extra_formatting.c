/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_formatting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:09:53 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/06 12:33:30 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

char		*fmt_p(t_mods mods, char *out_str)
{
	char	*new_str;
	char	*pad;
	int		padlen;

	padlen = 0;
	if (mods.precision != -1)
		return ("ERROR: 'p' does not use precision");
	if (mods.width != -1 && (mods.width > (int)ft_strlen(out_str)))
	{
		padlen = mods.width - ft_strlen(out_str);
		pad = (char *)malloc(sizeof(char) * padlen);
		ft_memset(pad, ' ', padlen);
		if (mods.flag != '\0')
		{
			if (mods.flag != '-')
				return ("ERROR: only the '-' flag applies to 's'");
			new_str = ft_strjoin(out_str, pad);
		}
		else
			new_str = ft_strjoin(pad, out_str);
	}
	else
		new_str = out_str;
	return (new_str);
}

char		*fmt_c(t_mods mods, char out_char)
{
	char	*tmp_str;
	char	*new_str;
	char	*pad;
	int		padlen;

	tmp_str = (char *)malloc(sizeof(char) * 1);
	tmp_str[0] = out_char;
	if (mods.width != -1)
	{
		padlen = mods.width - 1;
		new_str = (char *)malloc(sizeof(char) * mods.width);
		pad = (char *)malloc(sizeof(char) * padlen);
		ft_memset(pad, ' ', padlen);
		if (mods.flag != '\0')
		{
			if (mods.flag != '-')
				return ("ERROR: '-' flag does not apply to 'c'");
			new_str = ft_strjoin(tmp_str, pad);
		}
		else
			new_str = ft_strjoin(pad, tmp_str);
	}
	else
		new_str = tmp_str;
	return (new_str);
}

static char	*init_new_str(char *tmp_str, t_mods mods)
{
	int		padlen;
	char	*pad;

	padlen = mods.width - ft_strlen(tmp_str);
	pad = (char *)malloc(sizeof(char) * padlen);
	ft_memset(pad, ' ', padlen);
	if (mods.flag != '\0')
	{
		if (mods.flag != '-')
			return ("ERROR: '-' flag does not apply to 's'");
		return (ft_strjoin(tmp_str, pad));
	}
	else
		return (ft_strjoin(pad, tmp_str));
}

char		*fmt_s(t_mods mods, char *out_str)
{
	char	*tmp_str;
	char	*new_str;

	if (mods.precision != -1)
	{
		tmp_str = (char *)malloc(sizeof(char) * mods.precision + 1);
		ft_strncpy(tmp_str, out_str, mods.precision);
	}
	else
		tmp_str = out_str;
	if (mods.width != -1)
		new_str = init_new_str(tmp_str, mods);
	else
		new_str = tmp_str;
	return (new_str);
}
