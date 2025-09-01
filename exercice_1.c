#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>


int main()
{
	int fd;
	const char* message = "Hello, Linux File IO";

	fd = open( "hello.txt", O_RDONLY | O_CREAT | O_TRUNC, 06444);

	//write to file
	write(fd, message, strlen(message));


	//close file 
	close(fd);
	

	return 0;

}
