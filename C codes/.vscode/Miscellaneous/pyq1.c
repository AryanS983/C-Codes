#include <sys/types.h>

#include <sys/stat.h>

#include <unistd.h>

#include <stdio.h>

#include <string.h>

#include <fcntl.h>



#define DATASIZE 64



int main() {

	mkfifo("./myfifo1", 0666 | O_CREAT);

	while(1){

		int a,b;

		float c;

		printf("Enter 1st number: ");

		scanf("%d", &a);

		printf("\nEnter 2nd number: ");

		scanf("%d", &b);

		

		int fd = open ("./myfifo1", O_WRONLY);

		

		write (fd, &a, sizeof(a));

		write(fd, &b, sizeof(b));

		close(fd);

		if(a==0 && b==0){

			break;

		}

		

		int fd2 = open("./myfifo2", O_RDONLY);

		read(fd2,&c,sizeof(float));

		printf("\n%0.2f\n",c);

		

		close(fd2);

	}

	

	return 0;

}