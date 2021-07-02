#include "printlib.h"

/* Initialize <fdata> */
void	init_fdata(t_fdata *fdata)
{
	fdata->ljust = 0;
	fdata->zeros = 0;
	fdata->width = 0;
	fdata->precision = -1;
}

/* Returns the next int in <format>. 
Or the first int in <ap> if the first char founded in <format> is a [*].
Moves *<format> pass the chars used */
int	get_num(char **format, va_list ap)
{
	int	output;

	output = 0;
	if (**format != '*')
	{		
		output = ft_atoi(*format);
		if (output > 0)
			*format += ft_digitcount(output) - 1;
	}
	else
		output = va_arg(ap, int);
	return (output);
}

/* Sets the witdh of <fdata> to what is found in
<format> and <ap>. And moves *<format> pass the chars used */
void	set_width(char **format, va_list ap, t_fdata *fdata)
{
	fdata->width = get_num(format, ap);
	if (fdata->width < 0)
	{
		fdata->width *= -1;
		fdata->ljust = 1;
	}
}

/* Sets the precision of <fdata> to what is found in
<format> and <ap>. And moves *<format> pass the chars used */
void	set_precs(char **format, va_list ap, t_fdata *fdata)
{
	*format += 1;
	if (ft_isdigit(**format) || **format == '*')
		fdata->precision = get_num(format, ap);
	else
	{
		fdata->precision = 0;
		*format -= 1;
	}
}

/* Chech the format specifics and returns them as a t_fdata.
And moves <format> pass the chars used */
t_fdata	ft_format(char **format, va_list ap)
{
	t_fdata	fdata;

	init_fdata(&fdata);
	while (!valid_idnt(*++*format))
	{
		if (**format == '-')
			fdata.ljust = 1;
		else if (**format == '0' && fdata.zeros == 0)
			fdata.zeros = 1;
		else if (ft_isdigit(**format) || **format == '*')
			set_width(format, ap, &fdata);
		else if (**format == '.')
			set_precs(format, ap, &fdata);
	}
	return (fdata);
}
