#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_percentage(t_print *flag)
{
	flag->lenght += write(1, "%", 1);
	while (flag->dash && --flag->width > 0)
		flag->lenght += write(1, " ", 1);
}
