#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
	if(3 != argc){
		write(2,"Usage : mv  source_file destination_file\n",sizeof("Usage : mv  source_file destination_file\n"));
		exit(0);
	}

	if(0 > rename(argv[1],argv[2])){
		write(2,"Error While renaming the File\n", sizeof("Error While renaming the File\n"));
		exit(-1);
	}
	exit(0);
}
