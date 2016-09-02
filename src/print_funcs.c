/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:04:46 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/09/02 12:01:35 by mvanwyk          ###   ########.fr       */
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

static void	s_file_prent_long(struct s_file *sfile)
{
	ft_putstr(sfile->perms);
	ft_putchar(' ');
	ft_putstr(sfile->strhlinks);
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

/*
**	Block count must be modified to include/exclude hidden files depending on whether the -a option
**	is specified or not.
*/
void	blocks_print_total(struct s_file *sfile, t_lsargs lsargs)
{
	int	blocks;

	blocks = 0;
	ft_putstr("total ");
	while (sfile != NULL)
	{
		if (lsargs.show_all == 0)
		{
			if (sfile->name[0] != '.')
			{
				blocks += sfile->block_count;
			}
		}
		else
		{
			blocks += sfile->block_count;
		}
		sfile = sfile->next;
	}
	ft_putnbr_endl(blocks);
}

/*
void	blocks_print_total(struct s_file *sfile)
{
	int	blocks;

	blocks = 0;
	ft_putstr("total ");
	while (sfile != NULL)
	{
		blocks += sfile->block_count;
		sfile = sfile->next;
	}
	ft_putnbr_endl(blocks);
}
*/

void	s_file_print_members(struct s_file *sfile)
{
	while (sfile != NULL)
	{
		ft_putstr("Permissions:\t");
		ft_putendl(sfile->perms);
		ft_putstr("Hardlinks:\t");
		ft_putnbr_endl(sfile->hlinks);
		ft_putstr("User Name:\t");
		ft_putendl(sfile->uname);
		ft_putstr("Group Name:\t");
		ft_putendl(sfile->gname);
		ft_putstr("Size:\t\t");
		ft_putnbr_endl(sfile->size);
		ft_putstr("Modified Time:\t");
		ft_putendl(sfile->mod_time);
		ft_putstr("Name:\t\t");
		ft_putendl(sfile->name);
		ft_putstr("Is Directory:\t");
		ft_putnbr_endl(sfile->is_dir);
		ft_putstr("Directory Path:\t");
		ft_putendl(sfile->dir_path);
		ft_putchar('\n');
		sfile = sfile->next;
	}
}

void	handle_print(struct s_file *sfile, t_lsargs lsargs)
{
	if (lsargs.long_form == 1)
		blocks_print_total(sfile, lsargs);
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
