#include "printlib.h"

/* Returns 1 if <c> is a valid printf format identifier. 0 if not. */
int	valid_idnt(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

/* Determines what the specifier is and
calls to the corresponding print function.
Returns the number of chars printed */
int	det_spc(char spc, va_list ap, t_fdata fdata)
{
	if (spc == '%')
		return (print_char('%', fdata));
	if (spc == 'c')
		return (print_char(va_arg(ap, int), fdata));
	if (spc == 's')
		return (print_str(va_arg(ap, char *), fdata));
	if (spc == 'i' || spc == 'd')
		return (print_dec(va_arg(ap, int), fdata));
	if (spc == 'u')
		return (print_dec(va_arg(ap, unsigned), fdata));
	if (spc == 'x' || spc == 'X')
		return (print_hex(spc, va_arg(ap, int), fdata));
	if (spc == 'p')
		return (print_point(va_arg(ap, void *), fdata));
	return (0);
}

/* u know... the printf */
int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;
	t_fdata	fdata;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			fdata = ft_format((char **)&format, ap);
			count += det_spc(*format++, ap, fdata);
		}
		else
		{
			write(1, format, 1);
			format++;
			count++;
		}
	}
	va_end(ap);
	return (count);
}
