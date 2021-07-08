#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int ft_edit_variable(t_print *flag, const char *format, int i)
{
	if (format[i] == '%')
		ft_precentage(flag);
	else if (format[i] == 'p')
		ft_print_pointer(flag);
	else if (format[i] == 'x' || format[i] == 'X')
		ft_print_hexa(flag, format[i] - 23);
	else if (format[i] == 'c')
		ft_print_char(flag);
	else if (format[i] == 's')
		ft_print_str(flag);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_print_int(flag);
	else if (format[i] == 'u')
		ft_print_unsigned_int(flag);
	return (i);
}

int	ft_format(t_print *flag, const char *format, int i)
{
	while (!(ft_isalpha(format[i]) || format[i] == '%'))
	{
		if (ft_isdigit(format[i]))
			i = ft_edit_width(flag, format, i);
		if (format[i] == '-')
			i = ft_edit_dash(flag, i);
		if (format[i] == '0')
			i = ft_edit_zero(flag, format, i);
		if (format[i] == '.')
			i = ft_edit_dot(flag, format, i);
		if (format[i] == '*')
			i = ft_edit_star(flag, i);
		if (format[i] == ' ')
			i = ft_edit_space(flag, i);
	}
	ft_edit_variable(flag, format, i);
	ft_reset_flag(flag);
	return (i);
}