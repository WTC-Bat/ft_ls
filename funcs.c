#include "ft_ls.h"

int	s_file_length(struct s_dir *sdir)
{
	int		len;

	len = 0;
	while(sdir != NULL)
	{
		len++;
		sdir = sdir->next;
	}
	return (len);
}

void	s_file_sort(struct s_dir *sdir)
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

void	s_file_print(struct s_dir *sdir)
{
	while (sdir != NULL)
	{
		ft_putstr(sdir->dir_name);
		if (sdir->next == NULL)
			ft_putchar('\n');
		else
			ft_putstr("  ");
		sdir = sdir->next;
	}
}
