#include "includes/ft_printf.h"

int main()
{
	char *to_print;
	int ret;

	to_print = "Hello World !";
	ret = ft_printf("[%s]\n", to_print);
	ft_printf("ft_printf return value : %d\n", ret);
	return (0);
}
