/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:02:58 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/14 15:15:06 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static struct s_file	*s_file_getelems(DIR *d, t_lsargs lsargs)
{
	struct s_file	*root;
	struct s_file	*current;
	struct dirent	*dent;
	struct stat		st;
	struct passwd	*pd;
	struct group	*gp;
	char			*pth;

	root = NULL;
	while ((dent = readdir(d)) != NULL)
	{
		pth = ft_strjoin(lsargs.path, dent->d_name);
		stat(pth, &st);
		pd = getpwuid(st.st_uid);
		gp = getgrgid(st.st_gid);
		current = (struct s_file *)malloc(sizeof(struct s_file));
		current->perms = s_file_permissions(st);
		current->hlinks = st.st_nlink;
		current->uname = ft_strdup(pd->pw_name);
		current->gname = gp->gr_name;
		current->size = st.st_size;
		current->ttmtime = st.st_mtime;
		current->mod_time = format_time(&st.st_mtime);
		current->name = dent->d_name;
		current->is_dir = S_ISDIR(st.st_mode);
		//current->dir_path = ft_strjoin(lsargs.path, dent->d_name);	//!
		current->dir_path = pth;
		current->next = root;
		root = current;
	}
	format_size(root);
	//free(pth);
	return (root);
}

struct s_file	*s_file_init(t_lsargs lsargs)
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
	sfile = s_file_init(lsargs);
	initialize(sfile, lsargs);
	return (0);
}
