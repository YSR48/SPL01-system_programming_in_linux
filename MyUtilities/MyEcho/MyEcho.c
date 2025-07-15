#include <unistd.h>
#include <string.h>

int main(int argc, char **argv){
	if(argc == 1){
	       	write(1,"\n",1);
		return 0;
	}
	for(int i = 1; i < argc - 1 ;i++){
		write(1,argv[i],strlen(argv[i]));
		write(1," ",1);
	}
	write(1,argv[argc-1],strlen(argv[argc-1]));
	write(1,"\n",1);
	return 0;
}
