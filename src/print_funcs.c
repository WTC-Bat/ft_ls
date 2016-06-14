/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:04:46 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/14 15:21:34 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	s_file_prent_basic(struct s_file *sfile)
{
	ft_putstr(sfile->name);
	if (sfile->next == NULL)
		ft_putchar('\n');
	else
		ft_putstr("  ");
}

/*
static void	s_file_prent_basic(struct s_file *sfile, t_lsargs lsargs)
{
	struct s_file	*sfdir;

	ft_putstr(sfile->name);
	if (sfile->next == NULL)
		ft_putchar('\n');
	else
		ft_putstr("  ");

	if (sfile->is_dir == 1)
	{
		if (lsargs.recursive == 1)
		{
			ft_putchar('\n');
			lsargs.path = sfile->dir_path;	//!
			ft_putstr("LSARGS.PATH: ");
			ft_putendl(lsargs.path);
			sfdir = s_file_init(lsargs);
			s_file_prent_basic(sfdir, lsargs);
		}
	}
}
*/

static void	s_file_prent_long(struct s_file *sfile)
{
	ft_putstr(sfile->perms);
	ft_putchar(' ');
	ft_putnbr(sfile->hlinks);
	ft_putchar(' ');
	ft_putstr(sfile->uname);
	ft_putchar(' ');
	ft_putstr(sfile->gname);
	ft_putchar(' ');
	ft_putstr(sfile->strsize);
	ft_putchar(' ');
	ft_putstr(sfile->mod_time);
	ft_putchar(' ');
	ft_putstr(sfile->name);
	ft_putchar('\n');
}

void	s_file_print_members(struct s_file *sfile)
{
	while (sfile != NULL)
	{
		ft_putstr("Permissions:\t");
		ft_putendl(sfile->perms);
		ft_putstr("Hardlinks:\t");
		ft_putnbr(sfile->hlinks);
		ft_putchar('\n');
		ft_putstr("User Name:\t");
		ft_putendl(sfile->uname);
		ft_putstr("Group Name:\t");
		ft_putendl(sfile->gname);
		ft_putstr("Size:\t\t");
		ft_putnbr(sfile->size);
		ft_putchar('\n');
		ft_putstr("Modified Time:\t");
		ft_putendl(sfile->mod_time);
		ft_putstr("Name:\t\t");
		ft_putendl(sfile->name);
		ft_putstr("Is Directory:\t");
		ft_putnbr(sfile->is_dir);
		ft_putchar('\n');
		ft_putstr("Directory Path:\t");
		ft_putendl(sfile->dir_path);
		ft_putchar('\n');
		sfile = sfile->next;
	}
}

void	handle_print(struct s_file *sfile, t_lsargs lsargs)
{
	while (sfile != NULL)
	{
		if (sfile->name[0] == '.')
		{
			if (lsargs.show_all == 1)
			{
				if (lsargs.long_form == 1)
					s_file_prent_long(sfile);
				else
					s_file_prent_basic(sfile);
			}
		}
		else
		{
			if (lsargs.long_form == 1)
				s_file_prent_long(sfile);
			else
				s_file_prent_basic(sfile);
		}
		sfile = sfile->next;
	}
}
