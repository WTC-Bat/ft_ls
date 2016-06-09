#include "libft.h"

char	*ft_strlower(char const *str)
{
	char	*out_str;
	int		cnt;
	
	out_str = NULL;
	cnt = 0;	
	out_str = (char *)malloc(sizeof(str));
	while (str[cnt] != '\0')
	{
		if (ft_isupper(str[cnt]))
			out_str[cnt] = ft_tolower(str[cnt]);
		else
			out_str[cnt] = str[cnt];
		cnt++;
	}
	out_str[cnt] = '\0';
	return (out_str);
}
