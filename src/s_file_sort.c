/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_file_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:05:05 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/08/30 14:14:01 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	s_file_sort_az(struct s_file *sfile)
{
	struct s_file	*nxt;
	struct s_file	*root;

	nxt = sfile->next;
	root = sfile;
	while (nxt != NULL)
	{
		while (nxt != root)
		{
			if (ft_strcmp(root->name, nxt->name) > 0)
			{
				do_sort(root, nxt);
			}
			root = root->next;
		}
		root = sfile;
		nxt = nxt->next;
	}
}

void	s_file_sort_az_rev(struct s_file *sfile)
{
	struct s_file	*nxt;
	struct s_file	*root;

	nxt = sfile->next;
	root = sfile;
	while (nxt != NULL)
	{
		while (nxt != root)
		{
			if (ft_strcmp(root->name, nxt->name) < 0)
			{
				do_sort(root, nxt);
			}
			root = root->next;
		}
		root = sfile;
		nxt = nxt->next;
	}
}

void	s_file_sort_mtime(struct s_file *sfile)
{
	struct s_file	*nxt;
	struct s_file	*root;

	nxt = sfile->next;
	root = sfile;
	while (nxt->next != NULL)
	{
		while (nxt != root)
		{
			if (root->ttmtime < nxt->ttmtime)
			{
				do_sort(root, nxt);
			}
			root = root->next;
		}
		root = sfile;
		nxt = nxt->next;
	}
}

void	s_file_sort_mtime_rev(struct s_file *sfile)
{
	struct s_file	*nxt;
	struct s_file	*root;

	nxt = sfile->next;
	root = sfile;
	while (nxt->next != NULL)
	{
		while (nxt != root)
		{
			if (root->ttmtime > nxt->ttmtime)
			{
				do_sort(root, nxt);
			}
			root = root->next;
		}
		root = sfile;
		nxt = nxt->next;
	}
}
