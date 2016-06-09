/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:25:24 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/05 13:25:28 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

static char	*get_value_3(va_list vlst, t_mods mods, int fmtl_len)
{
	unsigned char			uschar;
	unsigned long long int	ullint;

	uschar = '\0';
	ullint = 0;
	if (mods.fmtl[fmtl_len - 2] == 'h' &&
		mods.fmtl[fmtl_len - 3] == 'h')
	{
		uschar = va_arg(vlst, int);
		return (ft_itoa(uschar));
	}
	else if (mods.fmtl[fmtl_len - 2] == 'l' &&
		mods.fmtl[fmtl_len - 3] == 'l')
	{
		ullint = va_arg(vlst, unsigned long long int);
		return (ft_itoa(ullint));
	}
	return ("Crckrs003");
}

static char	*get_value_2(va_list vlst, t_mods mods, int fmtl_len)
{
	unsigned short int	ushint;
	size_t				szt;

	ushint = 0;
	szt = 0;
	if (mods.fmtl[fmtl_len - 2] == 'h')
	{
		ushint = va_arg(vlst, int);
		return (ft_itoa(ushint));
	}
	else if (mods.fmtl[fmtl_len - 2] == 'z')
	{
		szt = va_arg(vlst, size_t);
		return (ft_itoa(szt));
	}
	else
		return (get_value_3(vlst, mods, fmtl_len));
	return ("Crckrs002");
}

static char	*get_value(va_list vlst, t_mods mods, int fmtl_len)
{
	unsigned long int	ulint;
	unsigned int		uint;

	ulint = 0;
	uint = 0;
	if (fmtl_len > 3)
		return ("ERROR: too many length modifiers");
	if (mods.fmtl[fmtl_len - 1] == 'U' || mods.fmtl[fmtl_len - 2] == 'l')
	{
		ulint = va_arg(vlst, unsigned long int);
		return (ft_itoa(ulint));
	}
	else if (mods.fmtl[fmtl_len - 2] == 'j')
	{
		uint = va_arg(vlst, unsigned int);
		return (ft_itoa(uint));
	}
	else
		return (get_value_2(vlst, mods, fmtl_len));
	return ("Crckrs001");
}

char		*handle_u(va_list vlst, t_mods mods)
{
	int		fmtl_len;
	int		ui;
	char	*out_str;

	fmtl_len = ft_strlen(mods.fmtl);
	ui = 0;
	if (fmtl_len > 1 || mods.fmtl[fmtl_len - 1] == 'U')
	{
		if (mods.fmtl[fmtl_len - 1] == 'U' && fmtl_len > 1)
			return ("ERROR: 'U' takes no length modifier");
		if (check_length(mods) == 0)
			return ("ERROR: unsupported length modifier for 'i'");
		out_str = get_value(vlst, mods, fmtl_len);
	}
	else
	{
		ui = va_arg(vlst, unsigned int);
		out_str = (char *)malloc(sizeof(char) * (ft_strlen(ft_itoa(ui)) + 1));
		out_str = ft_itoa(ui);
		out_str[ft_strlen(out_str)] = '\0';
	}
	return (fmt_u(mods, out_str));
}
