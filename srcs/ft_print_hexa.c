#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_hexa(t_print *flag, int c)
{
	unsigned int	j;
	int				len;
	char			*num;

	j = va_arg(flag->args, unsigned int);
	if (!j)
	{
		ft_write_zero(flag);
		return ;
	}
	len = ft_numlen_base(j, 16);
	num = malloc(len + 1);
	if (!num)
		return ;
	num = ft_itoa_base(num, j, 16, c);
	ft_update_flag(flag, len);
	ft_right_id(flag);
	while (num && len-- > 0)
		flag->lenght += write(1, &num[len], 1);
	ft_left_id(flag);
	free (num);
}

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

int	ft_check_sign(t_print *flag, int j)
{
	flag->sign = 1;
	flag->space = 0;
	return (j * -1);
}
