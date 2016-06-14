#include "libft.h"

char	*ft_appendc(char *str, int c)
{
	int		len;
	int		cnt;
	char	*out_str;

	len = ft_strlen(str);
	cnt = 0;
	out_str = (char *)malloc(sizeof(char) * (len + 2));
	while (cnt < len)
	{
		out_str[cnt] = str[cnt];
		cnt++;
	}
	out_str[cnt] = c;
	cnt++;
	out_str[cnt] = '\0';
	return (out_str);
}
