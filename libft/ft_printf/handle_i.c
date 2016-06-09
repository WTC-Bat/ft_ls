/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:49:44 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/05 13:49:46 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

static char	*get_value_3(va_list vlst, t_mods mods, int fmtl_len)
{
	signed char		schar;
	long long int	llint;

	schar = '\0';
	llint = 0;
	if (mods.fmtl[fmtl_len - 2] == 'h' &&
		mods.fmtl[fmtl_len - 3] == 'h')
	{
		schar = va_arg(vlst, int);
		return (ft_itoa(schar));
	}
	else if (mods.fmtl[fmtl_len - 2] == 'l' &&
		mods.fmtl[fmtl_len - 3] == 'l')
	{
		llint = va_arg(vlst, long long int);
		return (ft_itoa(llint));
	}
	else
		return ("??ERRor?!?");
	return ("Crackers");
}

static char	*get_value_2(va_list vlst, t_mods mods, int fmtl_len)
{
	short int	shint;
	size_t		szt;

	shint = 0;
	szt = 0;
	if (mods.fmtl[fmtl_len - 2] == 'h')
	{
		shint = va_arg(vlst, int);
		return (ft_itoa(shint));
	}
	else if (mods.fmtl[fmtl_len - 2] == 'z')
	{
		szt = va_arg(vlst, size_t);
		return (ft_itoa(szt));
	}
	else
		return (get_value_3(vlst, mods, fmtl_len));
	return ("Crackers");
}

static char	*get_value(va_list vlst, t_mods mods, int fmtl_len)
{
	long int	lint;
	int			i;

	lint = 0;
	i = 0;
	if (fmtl_len > 3)
		return ("ERROR: too many length modifiers");
	if (mods.fmtl[fmtl_len - 1] == 'D' || mods.fmtl[fmtl_len - 2] == 'l')
	{
		lint = va_arg(vlst, long int);
		return (ft_itoa(lint));
	}
	else if (mods.fmtl[fmtl_len - 2] == 'j')
	{
		i = va_arg(vlst, int);
		return (ft_itoa(i));
	}
	else
		return (get_value_2(vlst, mods, fmtl_len));
	return ("Crackers");
}

char		*handle_i(va_list vlst, t_mods mods)
{
	int		fmtl_len;
	int		i;
	char	*out_str;

	fmtl_len = ft_strlen(mods.fmtl);
	i = 0;
	out_str = NULL;
	if (fmtl_len > 1 || mods.fmtl[fmtl_len - 1] == 'D')
	{
		if (mods.fmtl[fmtl_len - 1] == 'D' && fmtl_len > 1)
			return ("ERROR: 'D' takes no length modifier");
		if (check_length(mods) == 0)
			return ("ERROR: unsupported length modifier for 'i'");
		out_str = get_value(vlst, mods, fmtl_len);
	}
	else
	{
		i = va_arg(vlst, int);
		out_str = (char *)malloc(sizeof(char) * (ft_strlen(ft_itoa(i)) + 1));
		out_str = ft_itoa(i);
		out_str[ft_strlen(out_str)] = '\0';
	}
	return (fmt_i(mods, out_str));
}
