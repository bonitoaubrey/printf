#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_str(t_print *flag)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = 0;
	s = va_arg(flag->args, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	while (s[i])
		flag->lenght += write(1, &s[i++], 1);
}
