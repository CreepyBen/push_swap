#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int	a;
	int	b;

	a = ft_printf("%c %s %d %u %x %X %p %%\n", 'A', "hi", -42, 42, 255, 255, &a);
	b = printf("%c %s %d %u %x %X %p %%\n", 'A', "hi", -42, 42, 255, 255, &a);
	printf("ft=%d real=%d\n", a, b);
	return (0);
}