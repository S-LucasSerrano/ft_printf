#include "printlib.h"

/* Prints <num> according to the format indicated in <fdata>
Returns the number of printed characters */
int	print_dec(long num, t_fdata fdata)
{
	int	count;

	if (fdata.precision == 0 && num == 0)
		return (put_x_chars(' ', fdata.width));
	count = ft_digitcount(num);
	if (num < 0)
		fdata.width--;
	if (fdata.precision < 0 && fdata.ljust == 0 && fdata.zeros == 1)
		fdata.precision = fdata.width;
	if (count > fdata.precision)
		fdata.precision = count;
	if (fdata.ljust == 0)
		count += put_x_chars(' ', fdata.width - fdata.precision);
	if (num < 0)
	{
		count += write(1, "-", 1);
		num *= -1;
	}
	count += put_x_chars('0', fdata.precision - ft_digitcount(num));
	ft_putlong_fd(num, 1);
	if (fdata.ljust == 1)
		count += put_x_chars(' ', fdata.width - fdata.precision);
	return (count);
}
