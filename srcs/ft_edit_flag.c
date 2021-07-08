#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_edit_dot(t_print *flag, const char *format, int i)
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
	flag->precision = num;
	return (i);
}

int	ft_edit_width(t_print *flag, const char *format, int i)
{
	int	num;

	num = ft_atoi(&format[i]);
	i += ft_numlen(num);
	flag->width = num;
	return (i);
}

int	ft_edit_dash(t_print *flag, int i)
{
	i++;
	flag->dash = 1;
	return (i);
}

int	ft_edit_zero(t_print *flag, const char *format, int i)
{
	int	num;

	num = 0;
	i++;
	flag->zero = 1;
	while (format[i] == '0')
		i++;
	if (ft_isdigit(format[i]))
	{
		num = ft_atoi(&format[i]);
		i += ft_numlen(num);
	}
	flag->width = num;
	return (i);
}

int	ft_edit_star(t_print *flag, int i)
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
	return (i);
}

int	ft_edit_space(t_print *flag, int i)
{
	i++;
	flag->space = 1;
	return (i);
}