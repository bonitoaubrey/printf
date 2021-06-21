#include "../includes/ft_printf.h"

t_print	*ft_reset_flag(t_print *flag)
{
	flag->width = 0;
	flag->precision = 0;
	flag->zero = 0;
	flag->dot = 0;
	flag->sign = 0;
	flag->is_zero = 0;
	flag->dash = 0;
	flag->precent = 0;
	flag->space = 0;
	return (flag);
}

t_print	*ft_init_flag(t_print *flag)
{
	flag->width = 0;
	flag->precision = 0;
	flag->zero = 0;
	flag->dot = 0;
	flag->sign = 0;
	flag->lenght = 0;
	flag->is_zero = 0;
	flag->dash = 0;
	flag->precent = 0;
	flag->space = 0;
	return (flag);
}

int	ft_printf(const char *format, ...)
{
	t_print	*flag;
	int		i;
	int		word_count;

	if (!format)
		return (0);
	word_count = 0;
	flag = malloc(sizeof(t_print));
	if (!flag)
		return (-1);
	ft_init_flag(flag);
	i = -1;
	va_start(flag->args, format);
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_edit_format(flag, format, i + 1);
		else
			word_count += write(1, &format[i], 1);
	}
	word_count += flag->lenght;
	va_end(flag->args);
	free(flag);
	return (word_count);
}
