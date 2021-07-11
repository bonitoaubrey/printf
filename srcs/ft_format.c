#include "../includes/ft_printf.h"

int	ft_format(t_print *flag, const char *format, int i)
{
	if (format[i] == 'c')
		ft_print_char(flag);
	else if (format[i] == 'x' || format[i] == 'X')
		ft_print_hexa(flag, format[i] - 23);
	else if (format[i] == '%')
		ft_precentage(flag);
	else if (format[i] == 'p')
		ft_print_pointer(flag);
	else if (format[i] == 's')
		ft_print_str(flag);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_print_int(flag);
	else if (format[i] == 'u')
		ft_print_unsigned_int(flag);
	return (i);
}
