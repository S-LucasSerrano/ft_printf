#ifndef PRINTLIB_H
# define PRINTLIB_H

# include <stdarg.h>
# include "libft/libft.h"
# include <unistd.h>

/* Flags and format specifics founded after the '%' */
typedef struct s_format_data
{
	char	ljust;
	char	zeros;
	int		width;
	int		precision;
}					t_fdata;

int		ft_printf(const char *format, ...);
int		valid_idnt(char c);

t_fdata	ft_format(char **format, va_list ap);

int		print_char(char c, t_fdata fdata);
int		print_str(char *str, t_fdata fdata);
int		put_x_chars(char c, int amount);

int		print_dec(long num, t_fdata t_fdata);
int		print_unsg(unsigned num, t_fdata fdata);

int		print_hex(char x, int num, t_fdata fdata);
int		print_point(void *point, t_fdata fdata);

#endif