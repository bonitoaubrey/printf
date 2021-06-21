#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_edit_star(t_print *flag, const char *format, int i)
{
	i++;
	if (!flag->dot)
	{
		flag->width = va_arg(flag->args, int);
		if (flag->width < 0)
		{
			flag->width *= -1;
			flag->dash = 1;
			flag->zero = 0;
		}
	}
	else
	{
		flag->precision = va_arg(flag->args, int);
	}
	if (format[i] == '.')
		i = ft_edit_precision(flag, format, i);
	if (format[i] == '*')
		i = ft_edit_star(flag, format, i);
	while (format[i] == '*')
		i++;
	return (i);
}

int	ft_edit_precision(t_print *flag, const char *format, int i)
{
	int	num;

	num = 0;
	i++;
	flag->dot = 1;
	while (format[i] == '0')
		i++;
	if (ft_isdigit(format[i]))
	{
		num = ft_atoi(&format[i]);
		i += ft_numlen(num);
	}
	flag->precision = i;
	if (format[i] == '*')
		i = ft_edit_star(flag, format, i);
	while (format[i] == '*')
		i++;
	return (i);
}

int	ft_edit_width(t_print *flag, const char *format, int i)
{
	int	num;

	num = 0;
	if (ft_isdigit(format[i]))
	{
		num = ft_atoi(&format[i]);
		i += ft_numlen(num);
	}
	flag->width = 1;
	if (format[i] == '.')
		i = ft_edit_precision(flag, format, i);
	return (i);
}
