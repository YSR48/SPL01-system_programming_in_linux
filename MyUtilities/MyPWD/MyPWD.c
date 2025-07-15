#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int main(){
        char buff[PATH_MAX];
	char errMsg[] = "pwd: error: cannot get current directory\n";
        if(NULL != getcwd(buff,sizeof(buff))){
		write(1,buff,strlen(buff));
		write(1,"\n",1);
	} else {
		if(0 > write(2,errMsg,strlen(errMsg)))
			exit(-1);
		else
			exit(0);
	}
        return 0;

}

