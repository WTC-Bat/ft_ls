/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_file_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:04:55 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/09/02 11:07:53 by mvanwyk          ###   ########.fr       */
/*   Updated: 2016/08/30 15:26:53 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*s_file_permissions(struct stat st)
{
	char	*perms;

	perms = (char *)malloc(sizeof(char) * 11);
	ft_memset(perms, '-', 10);
	if (S_ISDIR(st.st_mode) > 0)
		perms[0] = 'd';
	if (st.st_mode & S_IRUSR)
		perms[1] = 'r';
	if (st.st_mode & S_IWUSR)
		perms[2] = 'w';
	if (st.st_mode & S_IXUSR)
		perms[3] = 'x';
	if (st.st_mode & S_IRGRP)
		perms[4] = 'r';
	if (st.st_mode & S_IWGRP)
		perms[5] = 'w';
	if (st.st_mode & S_IXGRP)
		perms[6] = 'x';
	if (st.st_mode & S_IROTH)
		perms[7] = 'r';
	if (st.st_mode & S_IWOTH)
		perms[8] = 'w';
	if (st.st_mode & S_IXOTH)
		perms[9] = 'x';
	perms[10] = '\0';
	return (perms);
}

int		s_file_length(struct s_file *sfile)
{
	int		len;

	len = 0;
	while(sfile != NULL)
	{
		len++;
		sfile = sfile->next;
	}
	return (len);
}

//char	*s_get_name(struct dirent *dent, struct stat st, char *pth)
char	*s_get_name(char *dnm, struct stat st, char *pth, t_lsargs la)
{
	char	*name;
	char	*realname;

	//name = dent->d_name;
	name = dnm;
	//name = ft_strdup(dnm);	<-?
	realname = NULL;
	if (S_ISLNK(st.st_mode) > 0)
	{
		if (la.long_form == 1)
		{
			realname = (char *)malloc(sizeof(char) * 1024);
			readlink(pth, realname, 1024);
			name = ft_strjoin(name, " -> ");
			name = ft_strjoin(name, realname);
		}
	}
	//else
	//{
	//	//name = dent->d_name;
	//	name = dnm;
	//}
	return (name);
}

void	s_file_format(struct s_file *sfile)
{
	format_size(sfile);
	format_links(sfile);
}

void	s_file_free(struct s_file *sfile)	////
{
	if (sfile->dir_path != NULL)
		free(sfile->dir_path);
	free(sfile->uname);
	free(sfile->gname);
	//
	free(sfile);
}
