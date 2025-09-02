
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

int main(){
	



	int fd;
	//open hell.txt
	fd = open("../exercice1/hello.txt", O_RDONLY, 0664);
	//catch error
	if(fd == -1){
		perror("open");
		return 1;
	}

	char buffer[128];
	ssize_t bytesRead;

	while( ( bytesRead = read(fd, buffer, sizeof(buffer ) - 1))  > 0){
			buffer[bytesRead] = '\0';
			printf("%s", buffer);


			
			}


			if ( bytesRead = -1){
		
				perror("read");
			}
	


			close(fd);

	return 0;
}
