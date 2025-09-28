#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(){



	int result = system("ls -la");
	if(result == -1)
	{
		printf("System call failed\n");
	}
	else if(WIFEXITED(result)){

		printf("Command exited with status: %d\n", WEXITSTATUS(result));
	}
	else{
		printf("Command terminated abnormally\n");
	}

	return 0;
}

