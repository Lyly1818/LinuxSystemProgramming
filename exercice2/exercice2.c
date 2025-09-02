
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
	



	int fd;
	//open hell.txt
	fd = open("../exercice1/hello.txt", O_RDONLY);
	//catch error
	if(fd == -1){
		perror("open");
		return 1;
	}

	char buffer[128];
	ssize_t bytesRead;

	while( ( bytesRead = read(fd, buffer, sizeof(buffer ) - 1))  > 0){
		//	buffer[bytesRead] = '\0';
		//
		//	printf("%s", buffer);
			//write directly to stdout
			if( write(STDOUT_FILENO, buffer, bytesRead) == bytesRead) {
				perror("write");
				close(fd);
				exit(EXIT_FAILURE);


			
			
			}
	}


			if ( bytesRead == -1){
		
				perror("read");
			}
	


			close(fd);

	return 0;
}
