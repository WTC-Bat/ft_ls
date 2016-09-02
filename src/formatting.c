/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:02:45 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/09/02 13:32:22 by mvanwyk          ###   ########.fr       */
/*   Updated: 2016/08/30 15:27:30 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	get_longest_size(struct s_file *sfile)
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

static int	get_longest_links(struct s_file *sfile)
{
	int		longest;
	int		len;

	longest = 0;
	while (sfile != NULL)
	{
		len = ft_strlen(ft_itoa(sfile->hlinks));
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
	char			*pad;
	int				longest;
	int				len;

	longest = get_longest_size(sfile);
	ft_putendl("GET LONGEST SIZE DONE");
	//pad = NULL;
	while (sfile != NULL)
	{
		fsize = ft_itoa(sfile->size);
		len = ft_strlen(fsize);
		if (len < longest)
		{
			ft_putendl("PRE-MALLOC SZ");
			ft_putnbr_endl((longest - len));
			pad = (char *)malloc(sizeof(char) * (longest - len));
			ft_putendl("POST-MALLOC SZ");
			ft_memset(pad, ' ', (longest - len));
			fsize = ft_strcat(pad, fsize);
			//fsize = ft_strjoin(pad, fsize);	////
			pad = NULL;
			free(pad);
		}
		//sfile->strsize = fsize;
		sfile->strsize = ft_strdup(fsize);
		//sfile->strsize = pad;
		sfile = sfile->next;
	}
}

void		format_links(struct s_file *sfile)
{
	char	*flinks;
	char	*pad;
	int		longest;
	int		len;

	ft_putendl("GET LONGEST LINKS DOING");
	longest = get_longest_links(sfile);
	ft_putendl("GET LONGEST LINKS DONE");
	pad = NULL;
	while (sfile != NULL)
	{
		flinks = ft_itoa(sfile->hlinks);
		len = ft_strlen(flinks);
		if (len < longest)
		{
			ft_putendl("PRE-MALLOC LNK");
			pad = (char *)malloc(sizeof(char) * (longest - len));
			ft_putendl("POST-MALLOC LNK");
			ft_memset(pad, ' ', (longest - len));
			flinks = ft_strcat(pad, flinks);
			//flinks = ft_strjoin(pad, flinks);
			pad = NULL;
			free(pad);
		}
		//sfile->strhlinks = flinks;	//?
		sfile->strhlinks = ft_strdup(flinks);	////
		//free(flinks);							////
		//sfile->strhlinks = pad;	//?
		sfile = sfile->next;
	}
}
