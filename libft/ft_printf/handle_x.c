/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:27:22 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/05 15:57:30 by mvanwyk          ###   ########.fr       */
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
		return (ft_itobase(uschar, 16));
	}
	else if (mods.fmtl[fmtl_len - 2] == 'l' &&
		mods.fmtl[fmtl_len - 3] == 'l')
	{
		ullint = va_arg(vlst, unsigned long long int);
		return (ft_itobase(ullint, 16));
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
		return (ft_itobase(ushint, 16));
	}
	else if (mods.fmtl[fmtl_len - 2] == 'z')
	{
		szt = va_arg(vlst, size_t);
		return (ft_itobase(szt, 16));
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
	if (mods.fmtl[fmtl_len - 2] == 'l')
	{
		ulint = va_arg(vlst, unsigned long int);
		return (ft_itobase(ulint, 16));
	}
	else if (mods.fmtl[fmtl_len - 2] == 'j')
	{
		uint = va_arg(vlst, unsigned int);
		return (ft_itobase(uint, 16));
	}
	else
		return (get_value_2(vlst, mods, fmtl_len));
	return ("Crckrs001");
}

char		*handle_x(va_list vlst, t_mods mods)
{
	int		fmtl_len;
	int		i;
	char	*out_str;

	fmtl_len = ft_strlen(mods.fmtl);
	i = 0;
	if (fmtl_len > 1)
	{
		if (check_length(mods) == 0)
			return ("ERROR: unsupported length modifier for 'o'");
		out_str = get_value(vlst, mods, fmtl_len);
	}
	else
	{
		i = va_arg(vlst, int);
		out_str = ft_itobase(i, 16);
		out_str[ft_strlen(out_str) + 1] = '\0';
	}
	if (mods.fmtl[fmtl_len - 1] == 'x')
		out_str = ft_strlower(out_str);
	return (fmt_x(mods, out_str));
}
