#include "printlib.h"

/* Writes x <amount> of char <c> 
Returns the number of printed characters */
int	put_x_chars(char c, int amount)
{
	int	count;

	if (amount <= 0)
		return (0);
	count = 0;
	while (count < amount)
	{
		write(1, &c, 1);
		count++;
	}
	return (count);
}

/* Prints <c> according to the format indicated in <fdata>
Returns the number of printed characters */
int	print_char(char c, t_fdata fdata)
{
	int	count;

	count = 1;
	if (fdata.ljust == 0)
	{
		if (fdata.zeros == 0)
			count += put_x_chars(' ', fdata.width - 1);
		else
			count += put_x_chars('0', fdata.width - 1);
	}
	write (1, &c, 1);
	if (fdata.ljust == 1)
		count += put_x_chars(' ', fdata.width - 1);
	return (count);
}

/* Writes <n> bytes of <str> 
Returns the number of printed characters */
int	putstr(char *str, int n)
{
	return (write(1, str, n));
}

/* Prints <str> according to the format indicated in <fdata>
Returns the number of printed characters */
int	print_str(char *str, t_fdata fdata)
{
	int	count;

	if (!str)
		str = "(null)";
	if (!*str)
		return (0);
	count = 0;
	if (fdata.precision < 0 || fdata.precision > (int)ft_strlen(str))
		fdata.precision = ft_strlen(str);
	if (fdata.ljust == 0)
	{
		if (fdata.zeros == 0)
			count += put_x_chars(' ', fdata.width - fdata.precision);
		else
			count += put_x_chars('0', fdata.width - fdata.precision);
	}
	count += putstr(str, fdata.precision);
	if (fdata.ljust == 1)
		count += put_x_chars(' ', fdata.width - fdata.precision);
	return (count);
}
