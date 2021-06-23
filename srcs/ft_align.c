#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_right_cs(t_print *flag, int len)
{
	while (flag->zero && flag->width-- > len)
		flag->lenght += write(1, "0", 1);
	if (!flag->zero && flag->precision && flag->precision < len)
		while (flag->width-- > flag->precision)
			flag->lenght += write(1, " ", 1);
	else
		while (!flag->zero && flag->width-- > len)
			flag->lenght += write(1, " ", 1);
}
