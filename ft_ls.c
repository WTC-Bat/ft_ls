#include "ft_ls.h"
//
#include "s_file_funcs.c"
#include "arg_funcs.c"
#include "print_funcs.c"

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

	//stat(lsargs.path, &st);		//!
	//pd = getpwuid(st.st_uid);	//!
	//gp = getgrgid(st.st_gid);	//!
	while ((dent = readdir(d)) != NULL)
	{
		stat(dent->d_name, &st);		//!
		pd = getpwuid(st.st_uid);	//!
		gp = getgrgid(st.st_gid);	//!
		current = (struct s_file *)malloc(sizeof(struct s_file));
		current->perms = s_file_permissions(st);
		current->hlinks = st.st_nlink;
		current->uname = ft_strdup(pd->pw_name);
		current->gname = gp->gr_name;
		current->size = (size_t)st.st_size;
		//current->mod_time = ctime(&st.st_mtime);	//!	mod_time as char *
		current->mod_time = st.st_mtime;
		current->name = dent->d_name;
		current->is_dir = S_ISDIR(st.st_mode);
		current->dir_path = ft_strjoin(lsargs.path, dent->d_name);
		current->next = root;
		root = current;
	}
	free(current);	//?!
	return (root);
}

static struct s_file	*s_file_init(t_lsargs lsargs)
{
	DIR				*d;
	struct s_file	*sfile;

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

int		main(int argc, char **argv)
{
	struct s_file	*sfile;
	t_lsargs		lsargs;

	if (argc == 0)
		exit(1);

	lsargs = analyze_args(argv);
	sfile = s_file_init(lsargs);
	s_file_sort(sfile);

	ft_putnbr(sfile->hlinks);
	ft_putchar('\n');
	ft_putendl(sfile->uname);
	ft_putendl(sfile->gname);
	ft_putnbr(sfile->size);
	ft_putchar('\n');
	//ft_putstr(sfile->mod_time);
	ft_putnbr(sfile->mod_time);
	ft_putchar('\n');
	ft_putendl(sfile->name);
	ft_putnbr(sfile->is_dir);
	ft_putchar('\n');
	ft_putendl(sfile->dir_path);

	s_file_print_all(sfile);
	return (0);
}
