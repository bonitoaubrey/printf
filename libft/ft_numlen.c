#include "libft.h"

int	ft_numlen(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len += 1;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
