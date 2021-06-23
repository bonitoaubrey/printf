#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_left_id(t_print *flag)
{
	if (flag->dash)
	{
		while (flag->zero && --flag->precision > -1)
			flag->lenght += write(1, "0", 1);
		while (--flag->width > -1)
			flag->lenght += write(1, " ", 1);
	}
}

void	ft_right_id(t_print *flag)
{
	if (flag->space)
		flag->lenght += write(1, " ", 1);
	if (flag->sign)
	{
		if (flag->zero || flag->dash || (!flag->width && !flag->precision))
		{
			flag->lenght += write(1, "-", 1);
			flag->sign = 0;
		}
	}
	if (!flag->dash)
	{
		while (!flag->zero && --flag->width > -1)
			flag->lenght += write(1, " ", 1);
		while (flag->zero && --flag->width > -1)
			flag->lenght += write(1, "0", 1);
		if (flag->sign)
			flag->lenght += write (1, "-", 1);
	}
	while (--flag->precision > -1)
		flag->lenght += write(1, "0", 1);
}

void	ft_right_zero(t_print *flag)
{
	if (flag->width && (flag->dot || flag->zero))
	{
		if (!flag->precision)
		{
			while (flag->zero && flag ->width-- > 0)
				flag->lenght += write(1, "0", 1);
			while (!flag->zero && flag->width-- > 0)
				flag->lenght += write(1, " ", 1);
		}
		else
		{
			flag->width -= flag->precision;
			while (flag->dash && flag ->precision-- > 0)
				flag->lenght += write(1, "0", 1);
			while (flag->width-- > 0)
				flag->lenght += write(1, " ", 1);
			while (!flag->dash && flag->precision-- > 0)
				flag-> lenght += write(1, "0", 1);
		}
	}
	else if (flag->dot)
		ft_write_zero_point(flag);
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
