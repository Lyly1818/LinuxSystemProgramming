#include <stdio.h>
#include <unistd.h>

int main(void) 
{

	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fork failed");
		return 1;
	}

	if(pid == 0)
	{
		//child process
		printf("Hello form child pid = %d\n ppid = %d\n",getpid(), getppid());

	}
	else {

		printf("Hello from parent pid = %d, Child PID = %d\n", getpid(), pid); 
			   	
	}







	return 0;
}
