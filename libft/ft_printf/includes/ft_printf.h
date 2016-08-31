/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 12:45:17 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/07 17:02:41 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ft_printf_H
# define ft_printf_H

# include <stdarg.h>
#include "../../libft.h"

typedef struct	s_mods
{
	int		width;
	int		precision;
	char	flag;
	char	*fmtl;
}				t_mods;

int				check_length(t_mods mods);
int				ft_printf(char *format, ...);
int				get_width(va_list vlst, char *fstr);
int				get_precision(va_list vlst, char *fstr);
int				haslength(char *fstr);
int				hasprecision(char *fstr);
int				haswidth(char *fstr);
int				hasflag(char *fstr);
int				istype(int c);
int				islength(int c);
int				isprecision(int c);
int				iswidth(char *fstr);
int				isflag(int c);
char			*fmt_c(t_mods mods, char out_char);
char			*fmt_i(t_mods mods, char *out_str);
char			*fmt_o(t_mods mods, char *out_str);
char			*fmt_p(t_mods mods, char *out_str);
char			*fmt_s(t_mods mods, char *out_str);
char			*fmt_u(t_mods mods, char *out_str);
char			*fmt_x(t_mods mods, char *out_str);
char			*handle_cap_c(va_list vlst, t_mods mods);
char			*handle_c(va_list vlst, t_mods mods);
char			*handle_cap_s(va_list vlst, t_mods mods);
char			*handle_i(va_list vlst, t_mods mods);
char			*handle_o(va_list vlst, t_mods mods);
char			*handle_p(va_list vlst, t_mods mods);
char			*handle_s(va_list vlst, t_mods mods);
char			*handle_u(va_list vlst, t_mods mods);
char			*handle_x(va_list vlst, t_mods mods);
char			*handle_type_1(va_list vlst, t_mods mods);

#endif
