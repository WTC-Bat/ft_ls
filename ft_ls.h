#include <dirent.h>
#include <pwd.h>
#include <unistd.h>
#include "libft/libft.h"

#ifndef FT_LS_H
# define FT_LS_H

struct	s_dir
{
	char			*dir_name;
	struct s_dir	*next;
};

typedef struct	s_lsargs
{
	int		show_all;
	int		long_form;
	int		recursive;
	int		reverse;
	int		order_time;
	int		has_path;
	char	*path;
}				t_lsargs;

struct	s_file
{
	//char			*perms;
	int				*hlinks;
	char			*uname;
	char			*gname;
	size_t			*size;
	char			*name;
	int				*is_dir;
	struct s_file	*next;
};

int		s_file_length(struct s_dir *sdir);
void	s_file_print(struct s_dir *sdir);
void	s_file_sort(struct s_dir *sdir);

#endif
