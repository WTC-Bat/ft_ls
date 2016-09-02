/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:02:58 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/09/02 12:46:51 by mvanwyk          ###   ########.fr       */
/*   Updated: 2016/08/30 15:26:41 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void				getelems2(struct s_file *current, struct stat st)
{
	struct passwd	*pd;
	struct group	*gp;

	pd = getpwuid(st.st_uid);
	gp = getgrgid(st.st_gid);
	ft_putendl("GETTING PERMS");
	current->perms = s_file_permissions(st);
	current->hlinks = st.st_nlink;
	current->uname = ft_strdup(pd->pw_name);
	//current->gname = gp->gr_name;
	current->gname = ft_strdup(gp->gr_name);
	current->size = st.st_size;
	current->ttmtime = st.st_mtime;
	current->mod_time = format_time(&st.st_mtime);
	current->block_count = st.st_blocks;
	current->is_dir = 0;
	//current->dir_path = "";
	current->dir_path = NULL;
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
		lstat(pth, &st);
		current = (struct s_file *)malloc(sizeof(struct s_file));
		//current->name = dent->d_name;
		//current->name = s_get_name(dent, st, pth);
		ft_putendl("GETTING NAME");
		current->name = s_get_name(dent->d_name, st, pth, lsargs);
		ft_putendl("GOT NAME");
		getelems2(current, st);
		ft_putendl("GOTELEMS");
		if (S_ISDIR(st.st_mode) > 0)
		{
			current->is_dir = 1;
			//current->dir_path = pth;
			current->dir_path = ft_strdup(pth);
		}
		ft_putendl("IS_DIR-PASS");
		current->next = root;
		ft_putendl("CURRENT->NEXT");
		root = current;
		ft_putendl("ROOT = CURRENT");
		pth = NULL;				////
		ft_putendl("PTH = NULL");
		free(pth);				////
		ft_putendl("FREE(PTH)");
		//s_file_free(current);	////
	}
	s_file_format(root);
	ft_putendl("S_FILE_FORMAT DONE");
	//if (current != NULL)
	//	free(current);
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
	//free(sfile);//?
	free(lsargs.path);	//?	////
	s_file_free(sfile);		////
	return (0);
}
