#include <stdio.h>
#include <unistd.h>


int main(void)
{
	printf("Before exec: PID = %d\n", getpid());

	//replace this process wiuth ls -l
	execl("/bin/ls", "ls", "-l", NULL);


	//on failure 
	perror("exec failes");
	return 1;

}
