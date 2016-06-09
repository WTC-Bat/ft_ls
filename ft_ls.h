#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <pwd.h>
# include <unistd.h>
# include <time.h>
# include <grp.h>
# include <sys/stat.h>
//# include <sys/types.h>
# include "libft/libft.h"

typedef struct	s_lsargs
{
	int		show_all;
	int		long_form;
	int		recursive;
	int		reverse;
	int		order_time;
	char	*path;
}				t_lsargs;

struct			s_file
{
	//char			*perms;
	int				hlinks;
	char			*uname;
	char			*gname;
	size_t			size;
	char			*mod_time;
	char			*name;
	int				is_dir;
	char			*dir_path;
	struct s_file	*next;
};

int				s_file_length(struct s_file *sdir);
void			s_file_print(struct s_file *sdir);
void			s_file_sort(struct s_file *sdir);

#endif
