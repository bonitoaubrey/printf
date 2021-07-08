#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_write_point(t_print *flag)
{
	ft_update_len(NULL, flag, 0);
	flag->precision = 0;
	while (flag->width--)
		flag->lenght += write(1, " ", 1);
}

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

int	ft_update_len(char *s, t_print *flag, int len)
{
	if (s)
		len = ft_strlen(s);
	if (flag->precision > 0 && flag->precision < len)
		len = flag->precision;
	return (len);
}

void    ft_print_str(t_print *flag)
{
    char    *s;
    int     i;
    int     len;

    i = 0;
    len = 0;
    s = va_arg(flag->args, char *);
	if (!s)
    {
		s = "(null)";
        if (flag->precision < 6)
            flag->precision = 0;
    }
	if (s && flag->dot == 1 && flag->precision == 0)
		return (ft_write_point(flag));
    len = ft_update_len(s, flag, len);
	while (flag->width > len && flag->dash == 0)
		ft_right_cs(flag, len);
    if (flag->dot == 1)
        while (s[i] && flag->precision--)
           flag->lenght += write(1, &s[i++], 1);
    else
    {    
        while (s[i])
           flag->lenght += write(1, &s[i++], 1);
    }
	while (flag->dash == 1 && flag->width-- > len)
		flag->lenght += write(1, " ", 1);
}