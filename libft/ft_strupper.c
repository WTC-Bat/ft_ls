#include "libft.h"

char	*ft_strupper(char const *str)
{
	char	*out_str;
	int		cnt;
	
	out_str = NULL;
	cnt = 0;
	out_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[cnt] != '\0')
	{
		if (ft_islower(str[cnt]))
			out_str[cnt] = ft_toupper(str[cnt]);
		else
			out_str[cnt] = str[cnt];
		cnt++;
	}
	out_str[cnt] = '\0';
	return (out_str);
}
