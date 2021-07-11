#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		word_count;
	int		i;
	t_print	*flag;

	if (!format)
		return (0);
	word_count = 0;
	flag = malloc(sizeof(t_print));
	if (!flag)
		return (-1);
	flag->lenght = 0;
	i = -1;
	va_start(flag->args, format);
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_format(flag, format, i + 1);
		else
			word_count += write(1, &format[i], 1);
	}
	word_count += flag->lenght;
	va_end(flag->args);
	free(flag);
	return (word_count);
}
