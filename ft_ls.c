#include "ft_ls.h"
//
#include "funcs.c"

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

static struct s_file *s_file_getelems(DIR d)
{
	struct s_file	*root;
	struct s_file	*current;
	struct dirent	*dent;
	struct stat		*st;

	root = NULL;
	stat(path_name, st);
	while ((dent = readdir(d)) != NULL)
	{
		if (dent =
	}

}

static struct s_file	*s_file_init(char *path_name)
{
	DIR				*d;
	//struct dirent	*dent;
	//struct s_file	*root;
	//struct s_file	*current;
	//struct stat		*st;

	/*
	root = NULL;
	if ((d = opendir(path_name)) == NULL)
	{
		ft_putendl_fd("Error: No file/folder found.", 2);
		exit(1);
	}
	stat(path_name, st);
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
	s_file_sort(current);
	return (root);
	*/


	d = opendir(path_name);
	if (d == NULL)
	{
		ft_putendl("Error: ", 2);
		exit(1);
	}
	else
	{
		s_dir_getelems(d);
	}
}

static t_args	analyze_args(char **argv)
{
	int			scnt;
	int			ccnt;
	t_lsargs	targs;

	while (argv[scnt] != '\0')
	{
		while (argv[scnt][ccnt] != '\0')
		{
			if (argv[scnt][ccnt] == 'a'
			ccnt++;
		}
		ccnt = 0;
		scnt++;
	}
}

/*
static t_args	analyze_args(char **argv)
{
	int		cnt;
	t_lsargs	lsargs;

	cnt = 1;
	while (argv[cnt] != '\0')
	{
		if (argv[cnt] == "-l")
			targs.long_format = 1;
		else if (argv[cnt] == "-a")
			targs.show_all = 1;
		else if (argv[cnt] == "-r")
			targs.reverse = 1;
		else if (argv[cnt] == "-t")
			targs.order_time = 1;
		else if (argv[cnt] == "-R")
			targs.recursive = 1;
		else if (ft_strchr(argv[cnt], '/') != NULL)
		{
			targs.has_path = 1;
			targs.path = argv[cnt];
		}
		cnt++;
	}
	return (targs);
}
*/

int		main(int argc, char **argv)
{
	struct s_file	*sfile;
	t_args			targs;

	if (argc == 1)
		sfile = s_file_init("./");
	else
	{
		targs = analyze_args(argv);
	}
	//else if (argc == 2 && (ft_strchr(argv[1], '/') != NULL))
	//	sfile = s_file_init(argv[1]);
	s_file_print(sdir);
	return (0);
}
