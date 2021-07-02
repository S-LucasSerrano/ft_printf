# ft_printf | slucas-s

A library that contains a simplified replica of the printf C function.

```C
int	ft_printf(const char *format, ...)
```

This version can manege the format specifiers _'cspdiuxX%'_, the width, the precision and the flags _'-0*'_.
See _man printf_ or https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm, that were what I had as my main references to recreating the original printf function.

### How it works
It prints characters from _format_ until the _'%'_ is found. Then, checks what the flags indicated after the symbol are, and saves them into a _t_fdata_ struct, moving the format pointer passed the characters used. The struct contains the width, the precission and two boolean-like values for the _'-'_ and _'0'_ flags. Depending on what letter the format specifier is, a specific function that prints that type of format is called, passing the next variable argument of the list and the _t_fdata_ struct, so each one can manage the flags accordingly.

The _ft_printf_ function returns the number of printed chars.
