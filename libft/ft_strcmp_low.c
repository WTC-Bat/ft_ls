#include "libft.h"

int		ft_strcmp_low(char *s1, char *s2)
{
	char	*s1low;
	char	*s2low;

	s1low = ft_strlower(s1);
	s2low = ft_strlower(s2);
	while (*s1low == *s2low)
	{
		if (*s1low == 0)
			return (0);
		s1low++;
		s2low++;
	}
	return (*(unsigned char *)s1low - *(unsigned char *)s2low);
}
