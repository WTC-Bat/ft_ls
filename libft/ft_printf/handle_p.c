/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 13:17:24 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/06 12:37:24 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/includes/ft_printf.h"

char	*handle_p(va_list vlst, t_mods mods)
{
	unsigned long	ptr;
	char			*out_str;

	out_str = NULL;
	if (ft_strlen(mods.fmtl) > 1)
		return ("ERROR: 'p' takes no length modifier\n");
	ptr = va_arg(vlst, unsigned long);
	out_str = ft_itobase(ptr, 16);
	out_str = ft_prependc(out_str, 'x');
	out_str = ft_prependc(out_str, '0');
	out_str = ft_strlower(out_str);
	return (fmt_p(mods, out_str));
}
