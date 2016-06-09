#include <dirent.h>
#include "ft_ls.h"

/*
 *	ft_ls:
 *
 *	-NO_OPTION
 *		-	list non-hidden files in current directory
 *
 *	-l
 *		-	long form current directory
 *
 *	-R
 *		-	list non-hidden files in directory and all child directories
 *
 *	-r
 *		-	reverse order
 *
 *	-a
 *		- 	all files (hidden too)
 *
 *	-t
 *		-	sort by timestamp
 *
 *	-path_to_dir
 *		-	list files in specified dir
 *
 */

static int	s_dir_length(struct s_dir *sdir)
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

static void	*sort_s_dir(struct s_dir *sdir)
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

static void	print_s_dir(struct s_dir *sdir)
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

static struct s_dir	*get_contents(char *path_name)
{
	DIR				*d;
	struct dirent	*dent;
	struct s_dir	*root;
	struct s_dir	*current;

	root = NULL;
	if ((d = opendir(path_name)) == NULL)
	{
		ft_putendl_fd("Error: ", 2);
		exit(1);
	}
	while ((dent = readdir(d)) != NULL)
	{
		if (dent->d_name[0] != '.')
		{
			current = (struct s_dir *)malloc(sizeof(struct s_dir));
			current->dir_name = dent->d_name;
			current->next = root;
			root = current;
		}
	}
	sort_s_dir(current);
	return (root);
}

int		main(int argc, char **argv)
{
	struct s_dir	*sdir;

	if (argc == 1)
		sdir = get_contents("./");
	else if (argc == 2 && (ft_strchr(argv[1], '/') != NULL))
		sdir = get_contents(argv[1]);
	print_s_dir(sdir);
	return (0);
}
