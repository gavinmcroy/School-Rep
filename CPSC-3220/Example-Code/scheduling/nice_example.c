#include <stdio.h>
#include <unistd.h>

#define BIG 10000000L
#define DIVIDER 500


void do_busy_things(int niceval)
{
	nice(niceval); //set the nice value for the process

	for (long i=0; i < BIG; i++)
	{
		if (i % (BIG/DIVIDER) == 0)
		{
			printf("p=%d ---> %ld\n",niceval,i);
		}
	}
}

int main()
{

	if (fork() == 0)
	{
		do_busy_things(1);
	} else {
		do_busy_things(2);
	}
}
