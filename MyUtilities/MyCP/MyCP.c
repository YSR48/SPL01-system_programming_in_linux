#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define COUNT 		1024
int main(int argc, char **argv){
	int fdSource, fdDest;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
	ssize_t bytesReaded = 0;
	char buff[COUNT];

	if(argc != 3){
		if(0 < write(2, "cp old-file new-file\n", sizeof("cp old-file new-file\n")))
			exit(-1);
		exit(0);
	}

	if(0 > (fdSource = open(argv[1],O_RDONLY))){
		write(2,"Can't Open Source File",sizeof("Can't Open Source File"));
		exit(-1);
	}
	fdDest = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
	
	while(0 < (bytesReaded = read(fdSource,buff,COUNT))){
		if(bytesReaded != write(fdDest, buff, bytesReaded)){
			write(2,"error while copying the file\n",sizeof("error while copying the file\n"));
			exit(-2);
		}
	}

	if(0 > close(fdSource)){
		write(2,"Error While Closing Source File\n",sizeof("Error While Closing Source File\n"));
		exit(-3);
	}
	if(0 > close(fdDest)){
                write(2,"Error While Closing Destination File\n",sizeof("Error While Closing Destination File\n"));
                exit(-3);
        }
	return 0;

}
