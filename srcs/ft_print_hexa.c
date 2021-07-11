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
		flag->lenght += write(1, "0", 1);
		return ;
	}
	len = ft_numlen_base(j, 16);
	num = malloc(len + 1);
	if (!num)
		return ;
	num = ft_itoa_base(num, j, 16, c);
	while (num && len-- > 0)
		flag->lenght += write(1, &num[len], 1);
	free (num);
}

void	ft_print_pointer(t_print *flag)
{
	unsigned long	add;
	int				len;

	len = 2;
	add = (unsigned long)va_arg(flag->args, void *);
	if (!add)
	{
		flag->lenght += write(1, "0x0", 3);
		return ;
	}
	len += ft_numlen_base(add, 16);
	flag->lenght += write(1, "0x", 2);
	flag->lenght += ft_putnbr_base(add, "0123456789abcdef");
}
