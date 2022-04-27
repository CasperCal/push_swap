#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

void	ft_check_int(int n, int res)
{
	if (n == 1 && res > INT_MAX)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (n == -1 && res - 1 > INT_MAX)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

int main(void)
{
	ft_check_int(1, 21321354687987456);
}