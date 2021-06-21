#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_percentage(t_print *flag)
{
	while (flag->zero && !flag->dash && --flag->width)
		flag->lenght += write(1, "0", 1);
	while (!flag->dash && --flag->width > 0)
		flag->lenght += write(1, " ", 1);
	flag->lenght += write(1, "%", 1);
	while (flag->dash && --flag->width > 0)
		flag->lenght += write(1, " ", 1);
}
