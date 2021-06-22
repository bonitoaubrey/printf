#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_str(t_print *flag)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(flag->args, char *);
	if (!s)
		s = "(null)";
	while (s[i])
		flag->lenght += write(1, &s[i++], 1);
}
