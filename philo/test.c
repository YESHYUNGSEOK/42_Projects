# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

int	main(void)
{
	struct timeval	tv;
	int	a;
	int	b;
	int	result;

	gettimeofday(&tv, NULL);
	a = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	usleep(500000);
	gettimeofday(&tv, NULL);
	b = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	result = b - a;
	printf("exceed: %d\n", result);
}