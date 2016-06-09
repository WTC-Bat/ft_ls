#include "ft_ls.h"

char	*get_uname(struct passwd *pd)
{
	char	*uname;

	uname = (char *)malloc(sizeof(char) * (ft_strlen(pd->pw_name) + 1));
	uname = ft_strdup(pd->pw_name);
}
