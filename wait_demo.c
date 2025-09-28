#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{

	pid_t pid = fork();
	if(pid == 0)
	{

		printf("Child running ... PID = %d\n", getpid());
		sleep(60);
		printf("Child is exiting.\n");
		return 42;

	}else{
		int status;
		wait(&status); //wait for chjild toi finish
	
		printf("Parent collected child. Exit code = %d\n", WEXITSTATUS(status));
	}



	return 0;
}
