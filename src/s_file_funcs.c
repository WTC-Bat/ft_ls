/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_file_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:04:55 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/13 15:05:57 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*s_file_permissions(struct stat st)
{
	char	*perms;

	perms = (char *)malloc(sizeof(char) * 11);
	ft_memset(perms, '-', 10);
	if (S_ISDIR(st.st_mode) > 0)	//?
		perms[0] = 'd';				//?
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
