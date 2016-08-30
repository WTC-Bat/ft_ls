/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:02:37 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/30 14:14:54 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	do_sort3(struct s_file *root, struct s_file *nxt)
{	
	int		tmp_isdir;
	char	*tmp_path;

	tmp_isdir = root->is_dir;
	tmp_path = root->dir_path;
	root->is_dir = nxt->is_dir;
	root->dir_path = nxt->dir_path;
	nxt->is_dir = tmp_isdir;
	nxt->dir_path = tmp_path;
}

static void	do_sort2(struct s_file *root, struct s_file *nxt)
{
	size_t	tmp_size;
	char	*tmp_strsize;
	time_t	tmp_ttmtime;
	char	*tmp_mtime;
	char	*tmp_name;

	tmp_size = root->size;
	tmp_strsize = root->strsize;
	tmp_ttmtime = root->ttmtime;
	tmp_mtime = root->mod_time;
	tmp_name = root->name;
	root->size = nxt->size;
	root->strsize = nxt->strsize;
	root->ttmtime = nxt->ttmtime;
	root->mod_time = nxt->mod_time;
	root->name = nxt->name;
	nxt->size = tmp_size;
	nxt->strsize = tmp_strsize;
	nxt->ttmtime = tmp_ttmtime;
	nxt->mod_time = tmp_mtime;
	nxt->name = tmp_name;
	do_sort3(root, nxt);
}

void		do_sort(struct s_file *root, struct s_file *nxt)
{
	char	*tmp_perms;
	int		tmp_hlinks;
	char	*tmp_strhlinks;
	char	*tmp_uname;
	char	*tmp_gname;

	tmp_perms = root->perms;
	tmp_hlinks = root->hlinks;
	tmp_strhlinks = root->strhlinks;
	tmp_uname = root->uname;
	tmp_gname = root->gname;
	root->perms = nxt->perms;
	root->hlinks = nxt->hlinks;
	root->strhlinks = nxt->strhlinks;
	root->uname = nxt->uname;
	root->gname = nxt->gname;
	nxt->perms = tmp_perms;
	nxt->hlinks = tmp_hlinks;
	nxt->strhlinks = tmp_strhlinks;
	nxt->uname = tmp_uname;
	nxt->gname = tmp_gname;
	do_sort2(root, nxt);
}
