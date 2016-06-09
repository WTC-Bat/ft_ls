#include "ft_ls.h"

int		s_file_length(struct s_file *sfile)
{
	int		len;

	len = 0;
	while(sfile != NULL)
	{
		len++;
		sfile = sfile->next;
	}
	return (len);
}

void	s_file_sort(struct s_file *sfile)
{
	struct s_file	*nxt;
	struct s_file	*root;
	char			*tmp_name;
	char			*rname;
	char			*nname;

	nxt = sfile->next;
	root = sfile;
	while (nxt != NULL)
	{
		while (nxt != root)
		{
			if (ft_strcmp(root->name, nxt->name) > 0)
			{
				tmp_name = root->name;
				root->name = nxt->name;
				nxt->name = tmp_name;
			}
			root = root->next;
		}
		root = sfile;
		nxt = nxt->next;
	}
}

/*
void	s_file_sort_time(struct s_file *sfile)
{
	struct s_dir	*nxt;
	struct s_dir	*root;
	char			*tmp_name;

	nxt = sdir->next;
	root = sdir;
	while (nxt->next != NULL)
	{
		while (nxt != root)
		{
			if (ft_strcmp(root->dir_name, nxt->dir_name) > 0)
			{
				tmp_name = root->dir_name;
				root->dir_name = nxt->dir_name;
				nxt->dir_name = tmp_name;
			}
			root = root->next;
		}
		root = sdir;
		nxt = nxt->next;
	}
}
*/

void	s_file_print(struct s_file *sfile)
{
	while (sfile != NULL)
	{
		ft_putstr(sfile->name);
		if (sfile->next == NULL)
			ft_putchar('\n');
		else
			ft_putstr("  ");
		sfile = sfile->next;
	}
}
