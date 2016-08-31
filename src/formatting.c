/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:02:45 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/30 15:39:44 by mvanwyk          ###   ########.fr       */
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
		//ft_printf("GET SIZE STRLEN:\tPASS\n");
		if (len > longest)
			longest = len;
		//ft_printf("SIZE PRE-SFILE->NEXT:\tPASS\n");
		sfile = sfile->next;
		//ft_printf("SIZE SFILE->NEXT:\tPASS\n");
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
		//ft_printf("GET LINKS STRLEN:\tPASS\n");
		if (len > longest)
			longest = len;
		//ft_printf("LINKS PRE-SFILE->NEXT:\tPASS\n");
		sfile = sfile->next;
		//ft_printf("LINKS SFILE->NEXT:\tPASS\n");
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
	//ft_printf("GET_LONGEST_SIZE:\tPASS\n");
	pad = NULL;
	while (sfile != NULL)
	{
		fsize = ft_itoa(sfile->size);
		len = ft_strlen(fsize);
		if (len < longest)
		{
			//ft_printf("SIZE PRE-MALLOC:\tPASS\n");
			pad = (char *)malloc(sizeof(char) * (longest - len));
			//ft_printf("SIZE PRE-MEMSET:\tPASS\n");
			ft_memset(pad, ' ', (longest - len));
			//ft_printf("SIZE MEMSET:\tPASS\n");
			//ft_printf("SIZE PRE-STRCAT:\tPASS\n");
			fsize = ft_strcat(pad, fsize);
			//pad = ft_strcat(pad, fsize);
			//ft_printf("SIZE STRCAT:\tPASS\n");
			//ft_strclr(pad);
			pad = NULL;
			free(pad);
		}
		sfile->strsize = fsize;
		//sfile->strsize = pad;
		sfile = sfile->next;
	}
}

/*
void		format_size(struct s_file *sfile)
{
	char			*fsize;
	int				longest;
	int				cnt;
	int				len;

	longest = get_longest_size(sfile);
	//ft_printf("GET_LONGEST_SIZE:\tPASS\n");
	cnt = 0;
	while (sfile != NULL)
	{
		fsize = ft_itoa(sfile->size);
		len = ft_strlen(fsize);
		if (len < longest)
		{
			while (cnt < (longest - len))
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
*/

void		format_links(struct s_file *sfile)
{
	char	*flinks;
	char	*pad;
	int		longest;
	int		len;

	longest = get_longest_links(sfile);
	//ft_printf("GET_LONGEST_LINKS:\tPASS\n");
	pad = NULL;
	while (sfile != NULL)
	{
		flinks = ft_itoa(sfile->hlinks);
		////ft_printf("FLINKS-ITOA:\tPASS\n");
		len = ft_strlen(flinks);
		if (len < longest)
		{
			//ft_printf("LINKS PRE-MALLOC:\tPASS\t%i - %i\n", longest, len);
			pad = (char *)malloc(sizeof(char) * (longest - len));
			//ft_printf("LINKS PRE-MEMSET:\tPASS\n");
			ft_memset(pad, ' ', (longest - len));
			//ft_printf("LINKS MEMSET:\tPASS\n");
			//ft_printf("LINKS PRE-STRCAT:\tPASS\n");
			flinks = ft_strcat(pad, flinks);
			//pad = ft_strcat(pad, flinks);
			//ft_printf("LINKS STRCAT:\tPASS\t%s\n", flinks);
			pad = NULL;
			free(pad);
		}
		sfile->strhlinks = flinks;
		//sfile->strhlinks = pad;	//?
		sfile = sfile->next;
	}
}

/*
void		format_links(struct s_file *sfile)
{
	char	*flinks;
	int		longest;
	int		cnt;
	int		len;

	longest = get_longest_links(sfile);
	//ft_printf("GET_LONGEST_LINKS:\tPASS\n");
	cnt = 0;
	while (sfile != NULL)
	{
		flinks = ft_itoa(sfile->hlinks);
		//ft_printf("FLINKS-ITOA:\tPASS\n");
		len = ft_strlen(flinks);
		if (len < longest)
		{
			while (cnt < (longest - len))
			{
				//ft_printf("PRE-PREPENDC:\tPASS\n");
				flinks = ft_prependc(flinks, ' ');	//!??!? USE MEMSET & JOIN/CAT
				//ft_printf("PREPENDC:\tPASS\n");
				cnt++;
			}
			cnt = 0;
		}
		sfile->strhlinks = flinks;
		sfile = sfile->next;
	}
}
*/
