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
	if (flag->dot == 1)
		len = flag->precision;
	while (flag->width-- > len && flag->dash == 0)
		flag->lenght += write(1, " ", 1);
	if (flag->dot == 1)
		while (s[i] && flag->precision--)
			flag->lenght += write(1, &s[i++], 1);
	else
		while (s[i])
			flag->lenght += write(1, &s[i++], 1);
	while (flag->dash == 1 && flag->width-- + 1 > len)
		flag->lenght += write(1, " ", 1);
}
