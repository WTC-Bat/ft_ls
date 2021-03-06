#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <pwd.h>
# include <unistd.h>
# include <time.h>
# include <grp.h>
# include <sys/stat.h>
# include "../libft/libft.h"

typedef struct	s_lsargs
{
	int		show_all;
	int		long_form;
	int		recursive;
	int		reverse;
	int		order_time;
	int		all_members;
	char	*path;
}				t_lsargs;

struct			s_file
{
	char			*perms;
	int				hlinks;
	char			*strhlinks;
	char			*uname;
	char			*gname;
	size_t			size;
	char			*strsize;
	time_t			ttmtime;
	char			*mod_time;
	blkcnt_t		block_count;
	char			*name;
	int				is_dir;
	char			*dir_path;
	struct s_file	*next;
};

t_lsargs		analyze_args(char **argv);
int				arg_ispath(char *arg);
int				args_are_valid(char **argv);
void			do_sort(struct s_file *root, struct s_file *nxt);
char			*format_time(time_t *ttmtime);
void			format_links(struct s_file *sfile);
void			format_size(struct s_file *sfile);
void			handle_print(struct s_file *sfile, t_lsargs lsargs);
void			s_file_format(struct s_file *sfile);
void			s_file_free(struct s_file *sfile);
struct s_file	*s_file_init(t_lsargs lsargs);
int				s_file_length(struct s_file *sfile);
char			*s_file_permissions(struct stat st);
void			s_file_sort_az(struct s_file *sfile);
void			s_file_sort_az_rev(struct s_file *sfile);
void			s_file_print_members(struct s_file *sfile);
void			s_file_sort_mtime(struct s_file *sfile);
void			s_file_sort_mtime_rev(struct s_file *sfile);
//char			*s_get_name(struct dirent *dent, struct stat st, char *pth);
char			*s_get_name(char *dnm, struct stat st, char *pth, t_lsargs la);

#endif
