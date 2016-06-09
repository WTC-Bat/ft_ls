#include "ft_ls.h"
//
#include "s_file_funcs.c"
#include "arg_funcs.c"

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

static struct s_file *s_file_getelems(DIR *d, t_lsargs lsargs)
{
	struct s_file	*root;
	struct s_file	*current;
	struct dirent	*dent;
	struct stat		st;
	struct passwd	*pd;
	struct group	*gp;

	root = NULL;
	stat(lsargs.path, &st);
	pd = getpwuid(st.st_uid);
	gp = getgrgid(st.st_gid);
	ft_putendl("start while");
	while ((dent = readdir(d)) != NULL)
	{
		current = (struct s_file *)malloc(sizeof(struct s_file));
		current->hlinks = st.st_nlink;	//!
		current->uname = ft_strdup(pd->pw_name);
		current->gname = gp->gr_name;
		current->size = (size_t)st.st_size;	//!
		current->mod_time = ctime(&st.st_mtime);	//!
		current->name = dent->d_name;
		current->is_dir = S_ISDIR(st.st_mode);	//!
		current->dir_path = ft_strjoin(lsargs.path, dent->d_name);	//!
		current->next = root;
		root = current;
	}
	free(current);	//?!
	return (root);	//return (current);
}

static struct s_file	*s_file_init(t_lsargs lsargs)
{
	DIR				*d;
	//struct dirent	*dent;
	//struct s_file	*root;
	//struct s_file	*current;
	//struct stat		*st;
	struct s_file	*sfile;

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


	d = opendir(lsargs.path);
	if (d == NULL)
	{
		ft_putendl_fd("Error: Unable to opendir", 2);
		exit(1);
	}
	sfile = s_file_getelems(d, lsargs);
	closedir(d);
	return (sfile);
}

/*
static t_lsargs	analyze_args(char **argv)
{
	int			scnt;
	int			ccnt;
	t_lsargs	lsargs;

	scnt = 1;
	ccnt = 0;
	if (args_are_valid(argv) == 0)
	{
		ft_putendl_fd("Error: Bad option format.", 2);
		exit(1);
	}
	while (argv[scnt] != NULL)
	{
		if (arg_ispath(argv[scnt]) == 1)
		{
			ft_putendl("IS PATH");
			ft_putendl(argv[scnt]);
			lsargs.path = argv[scnt];
			scnt++;
			continue;
		}
		else
		{
			lsargs.path = "./";
			continue;
		}
		while (argv[scnt][ccnt] != '\0')
		{
			lsargs_set(argv[scnt][ccnt], lsargs);
			ccnt++;
		}
		ccnt = 0;
		scnt++;
	}
	//
	ft_putnbr(lsargs.show_all);
	ft_putchar('\n');
	ft_putnbr(lsargs.long_form);
	ft_putchar('\n');
	ft_putnbr(lsargs.recursive);
	ft_putchar('\n');
	ft_putnbr(lsargs.reverse);
	ft_putchar('\n');
	ft_putnbr(lsargs.order_time);
	ft_putchar('\n');
	ft_putendl(lsargs.path);
	//
	return (lsargs);
}
*/

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
	t_lsargs		lsargs;

	lsargs = analyze_args(argv);
	ft_putendl("args analyzed");
	sfile = s_file_init(lsargs);
	ft_putendl("s_file initialized");
	s_file_sort(sfile);
	ft_putendl("s_file sorted");
	//if (argc == 1)
	//	sfile = s_file_init("./");
	//else
	//{
	//	lsargs = analyze_args(argv);
	//	sfile = s_file_init(lsargs);
	//}
	//else if (argc == 2 && (ft_strchr(argv[1], '/') != NULL))
	//	sfile = s_file_init(argv[1]);
	s_file_print(sfile);
	return (0);
}
