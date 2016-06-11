#include "ft_ls.h"

void	s_file_print_all(struct s_file *sfile)
{
	struct s_file *root;//!

	root = sfile;//!
	while (sfile != NULL)
	{
		ft_putstr(sfile->name);
		if (sfile->next == NULL)
			ft_putchar('\n');
		else
			ft_putstr("  ");
		sfile = sfile->next;
	}
	sfile = root;//!
}

//void	s_file_print_long(struct s_file *sfile)
