/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:02:45 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/13 15:05:37 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	get_longest(struct s_file *sfile)
{
	int				longest;
	int				len;

	longest = 0;
	while (sfile != NULL)
	{
		len = ft_strlen(ft_itoa(sfile->size));
		if (len > longest)
			longest = len;
		sfile = sfile->next;
	}
	return (longest);
}

char		*format_time(time_t *ttmtime)
{
	char	*fmttime;

	fmttime = ctime(ttmtime);
	fmttime = ft_strsub(fmttime, 4, (ft_strlen(fmttime) - 13));
	return (fmttime);
}

void		format_size(struct s_file *sfile)
{
	char			*fsize;
	int				longest;
	int				cnt;
	int				len;

	longest = get_longest(sfile);
	cnt = 0;
	while (sfile != NULL)
	{
		fsize = ft_itoa(sfile->size);
		len = ft_strlen(fsize);
		if (len < longest)
		{
			while (cnt < (longest - len - 3))	//!
			{
				fsize = ft_prependc(fsize, ' ');
				cnt++;
			}
			cnt = 0;
		}
		sfile->strsize = fsize;
		sfile = sfile->next;
	}
}