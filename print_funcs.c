#include "ft_ls.h"

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
