#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	pid_t pid = fork();
	int x = 5;
	
	if( pid < 0 )
	{
		perror("Error creating child: ");
		return -1;	
	}
	
	else if( pid > 0 ) /* Parent process code */
	{
		//sleep(1);
		printf("Parent sys- Hello World\n");
		x+= 5;
		printf("x = %d\n", x);
	}
	
	else // child process code
	{
		printf("Child says - Hello Parent\n");
		x*=x;
		printf("x= %d\n", x);
	}	
	return 0;
}
	
