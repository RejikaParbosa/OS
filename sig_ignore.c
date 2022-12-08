#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t pid = fork();
	int i;
	
	if(pid<0)
	{
		perror("Error creating child process: ");
		return -1;
	}
	
	if(pid>0) // parent process
	{
		sleep(10);
		printf("Sending %u to child process.. \n");
	}
	else // child process
	{
		i=1;
		signal(SIGQUIT, SIG_IGN);
		while(i)
		{
			printf("Child process (%u): i=%d \n", getpid(), i);
			i++;
			sleep(1);
		}
		// kill(getppid(), 2); //to send signal from child to parent.
	}
	return 0;
}
