/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:02:37 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/13 15:05:33 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	do_sort2(struct s_file *root, struct s_file *nxt)
{
	time_t	tmp_ttmtime;
	char	*tmp_mtime;
	char	*tmp_name;
	int		tmp_isdir;
	char	*tmp_path;

	tmp_ttmtime = root->ttmtime;
	tmp_mtime = root->mod_time;
	tmp_name = root->name;
	tmp_isdir = root->is_dir;
	tmp_path = root->dir_path;
	root->ttmtime = nxt->ttmtime;
	root->mod_time = nxt->mod_time;
	root->name = nxt->name;
	root->is_dir = nxt->is_dir;
	root->dir_path = nxt->dir_path;
	nxt->ttmtime = tmp_ttmtime;
	nxt->mod_time = tmp_mtime;
	nxt->name = tmp_name;
	nxt->is_dir = tmp_isdir;
	nxt->dir_path = tmp_path;
}

void		do_sort(struct s_file *root, struct s_file *nxt)
{
	char	*tmp_perms;
	int		tmp_hlinks;
	char	*tmp_uname;
	char	*tmp_gname;
	size_t	tmp_size;

	tmp_perms = root->perms;
	tmp_hlinks = root->hlinks;
	tmp_uname = root->uname;
	tmp_gname = root->gname;
	tmp_size = root->size;
	root->perms = nxt->perms;
	root->hlinks = nxt->hlinks;
	root->uname = nxt->uname;
	root->gname = nxt->gname;
	root->size = nxt->size;
	nxt->perms = tmp_perms;
	nxt->hlinks = tmp_hlinks;
	nxt->uname = tmp_uname;
	nxt->gname = tmp_gname;
	nxt->size = tmp_size;
	do_sort2(root, nxt);
}
