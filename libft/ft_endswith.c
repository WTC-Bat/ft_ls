#include "libft.h"

int		ft_endswith(char *str, char* end)
{
	int		strlen;
	int		endlen;
	int		cnt;
	int		ecnt;

	strlen = ft_strlen(str);
	endlen = ft_strlen(end);
	cnt = strlen - endlen;
	ecnt = 0;
	while (cnt < strlen)
	{
		if (str[cnt] != end[ecnt])
			return (0);
		cnt++;
		ecnt++;
	}
	return (1);
}
