#include "printlib.h"

/* Prints <num> in hexadecimal according to the format indicated in <fdata>
Returns the number of printed characters */
int	print_hex(char x, int num, t_fdata fdata)
{
	int	count;

	if (fdata.precision == 0 && num == 0)
		return (put_x_chars(' ', fdata.width));
	count = ft_hexlen(num);
	if (fdata.precision < 0 && fdata.ljust == 0 && fdata.zeros == 1)
		fdata.precision = fdata.width;
	if (count > fdata.precision)
		fdata.precision = count;
	if (fdata.ljust == 0)
		count += put_x_chars(' ', fdata.width - fdata.precision);
	count += put_x_chars('0', fdata.precision - ft_hexlen(num));
	if (!ft_isupperalpha(x))
		ft_puthex_fd(num, 1);
	else
		ft_putupperhex_fd(num, 1);
	if (fdata.ljust == 1)
		count += put_x_chars(' ', fdata.width - fdata.precision);
	return (count);
}

/* Prints <point> according to the format indicated in <fdata>
Returns the number of printed characters */
int	print_point(void *point, t_fdata fdata)
{
	int	count;

	count = 2;
	count += ft_hexlen_long((unsigned long)point);
	if (!fdata.ljust && fdata.zeros == 0)
		count += put_x_chars(' ', fdata.width - count);
	write(1, "0x", 2);
	if (!fdata.ljust && fdata.zeros == 1)
		count += put_x_chars('0', fdata.width - count);
	ft_putlonghex_fd((unsigned long)point, 1);
	if (fdata.ljust)
		count += put_x_chars(' ', fdata.width - count);
	return (count);
}
