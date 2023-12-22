#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

/**
 * infinite_while - Func runs infinite while loop and returns nothing
 * Return: void (Success)
*/
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - Programme entry point that creates 5 zombie process.
 * Return: 0 (Success).
*/
int main(void)
{
	int child_processes = 0;
	pid_t pid;

	while (child_processes < 5)
	{
		pid = fork();
		if (!pid)
		{
			break;
		}
		printf("Zombie process created, PID: %i\n", (int)pid);
		child_processes++;
	}
	if (pid != 0)
	{
		infinite_while();
	}
	return (0);
}
