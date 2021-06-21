#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_pointer(t_print *flag)
{
	unsigned long	add;

	add = (unsigned long)va_arg(flag->args, void *);
	if (!add)
	{
		flag->lenght += write(1, "(nil)", 5);
		return ;
	}
	flag->lenght += write(1, "0x", 2);
	if (!(!add && flag->dot))
		flag->lenght += ft_putnbr_base(add, "0123456789abcdef");
}
