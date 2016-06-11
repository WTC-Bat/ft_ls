#include "ft_ls.h"
#include "do_sort.c"

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

	ft_putendl(perms);
	//perms[ft_strlen(perms)] = '\0';
	//free(perms);
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

void	s_file_sort(struct s_file *sfile)
{
	struct s_file	*nxt;
	struct s_file	*root;
	//char			*tmp_name;
	//char			*rname;
	//char			*nname;

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

void	s_file_sort_time(struct s_file *sfile)
{
	struct s_file	*nxt;
	struct s_file	*root;

	nxt = sfile->next;
	root = sfile;
	while (nxt->next != NULL)
	{
		while (nxt != root)
		{
			if (root->mod_time > nxt->mod_time)
			{
				do_sort(root, nxt);
			}
			root = root->next;
		}
		root = sfile;
		nxt = nxt->next;
	}
}
