#include "../includes/ft_printf.h"

void	ft_print_char(t_print *flag)
{
	char	c;

	c = va_arg(flag->args, int);
	flag->lenght += write(1, &c, 1);
}

void	ft_precentage(t_print *flag)
{
	flag->lenght += write(1, "%", 1);
}
