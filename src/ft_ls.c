/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:02:58 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/30 16:24:41 by mvanwyk          ###   ########.fr       */
/*   Updated: 2016/08/30 15:26:41 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void				getelems2(struct s_file *current, struct stat st)
{
	struct passwd	*pd;
	struct group	*gp;

	pd = getpwuid(st.st_uid);
	//ft_printf("GETPWUID:\tPASS\n");
	gp = getgrgid(st.st_gid);
	//ft_printf("GETGRGID:\tPASS\n");
	current->perms = s_file_permissions(st);
	//ft_printf("S_FILE_PERMISSIONS:\tPASS\n");
	current->hlinks = st.st_nlink;
	current->uname = ft_strdup(pd->pw_name);
	current->gname = gp->gr_name;
	current->size = st.st_size;
	current->ttmtime = st.st_mtime;
	current->mod_time = format_time(&st.st_mtime);
	//ft_printf("FORMAT_TIME:\tPASS\n");
	current->block_count = st.st_blocks;
	current->is_dir = 0;
	current->dir_path = "";
}

static struct s_file	*s_file_getelems(DIR *d, t_lsargs lsargs)
{
	struct s_file	*root;
	struct s_file	*current;
	struct dirent	*dent;
	struct stat		st;
	char			*pth;

	root = NULL;
	while ((dent = readdir(d)) != NULL)
	{
		pth = ft_strjoin(lsargs.path, dent->d_name);
		//ft_printf("PTH-JOIN:\tPASS\n");
		lstat(pth, &st);
		//ft_printf("LSTAT:\tPASS\n");
		current = (struct s_file *)malloc(sizeof(struct s_file));
		//current->name = dent->d_name;
		current->name = s_get_name(dent, st, pth);
		//ft_printf("S_GET_NAME:\tPASS\n");
		getelems2(current, st);
		//ft_printf("GETELEMS2:\tPASS\n");
		if (S_ISDIR(st.st_mode) > 0)
		{
			current->is_dir = 1;
			current->dir_path = pth;
		}
		//ft_printf("ISDIR:\tPASS\n");
		current->next = root;
		root = current;
		//free(pth);
	}
	//ft_printf("WHILELOOP:\tPASS\n");
	s_file_format(root);
	//ft_printf("S_FILE_FORMAT:\tPASS\n");
	return (root);
}

struct s_file	*s_file_init(t_lsargs lsargs)
{
	DIR				*d;
	struct s_file	*sfile;

	d = opendir(lsargs.path);
	//ft_printf("OPENDIR:\tPASS\n");
	if (d == NULL)
	{
		ft_putendl_fd("Error: Unable to opendir", 2);
		exit(1);
	}
	sfile = s_file_getelems(d, lsargs);
	//ft_printf("S_FILE_GETELEMS:\tPASS\n");
	closedir(d);
	return (sfile);
}

void					initialize(struct s_file *sfile, t_lsargs lsargs)
{
	if (lsargs.all_members == 1)
		s_file_print_members(sfile);
	else
	{
		if (lsargs.order_time == 1)
			if (lsargs.reverse == 1)
				s_file_sort_mtime_rev(sfile);
			else
				s_file_sort_mtime(sfile);
		else
			if (lsargs.reverse == 1)
				s_file_sort_az_rev(sfile);
			else
				s_file_sort_az(sfile);
		handle_print(sfile, lsargs);
	}
}

int						main(int argc, char **argv)
{
	struct s_file	*sfile;
	t_lsargs		lsargs;

	if (argc == 0)
		exit(1);
	lsargs = analyze_args(argv);
	//ft_printf("ANALYZE_ARGS:\tPASS\n");
	sfile = s_file_init(lsargs);
	//ft_printf("S_FILE_INIT:\tPASS\n");
	initialize(sfile, lsargs);
	//ft_printf("INITIALIZE:\tPASS\n");
	free(sfile);
	return (0);
}
