#include <dirent.h>
#include "libft.h"
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
 *	-path_to_dir
 *		-	list files in specified dir
 *
 */

static int	list_length(struct s_dir *sdir)
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

static void	*sort_list(struct s_dir *sdir)
{
	struct s_dir	*nxt;
	char			*tmp_name;

	nxt = sdir->next;
	//tmp_name = NULL;	//?!
	//		sdir->next != NULL?
	while (sdir->next != NULL)
	{
		ft_putnbr(ft_strcmp(sdir->dir_name, nxt->dir_name));
		if (ft_strcmp(sdir->dir_name, nxt->dir_name) > 0)
		{
			tmp_name = sdir->dir_name;
			sdir->dir_name = nxt->dir_name;
			nxt->dir_name = tmp_name;
		}
		sdir = sdir->next;
		nxt = nxt->next;
	}
	
}

static void	list_contents(char *path_name)
{
	DIR				*d;
	struct dirent	*dent;
	struct s_dir	*root;
	struct s_dir	*current;

	root = NULL;
	//if (dir = opendir(path_name) == NULL)
	d = opendir(path_name);
	if (d == NULL)
	{
		ft_putendl_fd("Error: ", 2);
		exit(1);
			//current->next = NULL;
			//current->next = NULL;
	}
	while ((dent = readdir(d)) != NULL)
	{
		if (dent->d_name[0] != '.')
		{
			current = (struct s_dir *)malloc(sizeof(struct s_dir));
			current->dir_name = dent->d_name;
			//current->next = NULL;
			current->next = root;
			root = current;
		}
			//current->next = NULL;
	}
	current = root;
	ft_putnbr(list_length(current));
	ft_putchar('\n');
	sort_list(current);
	while (current != NULL)
	{
		ft_putstr(current->dir_name);
		ft_putchar('\t');
		current = current->next;
	}
	
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		list_contents("./");
	}
}
