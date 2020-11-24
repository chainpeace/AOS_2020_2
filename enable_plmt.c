#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_NAME_LEN 32

void main(int argc, char *argv[]){
	if(argc > 2){
		printf("Usage : \n");
		printf("./enable_plmt [command name]\n");
		printf("or to diable :\n");
		printf("./enable_plmt\n");
		return;
	}
	

	char process_name[MAX_NAME_LEN];
	if(argv[1]){
		strcpy(process_name, argv[1]);
		printf("enable plmt using process name : %s\n", process_name);
	} else{
		strcpy(process_name, "");
		printf("disable plmt\n");
	}
	syscall(436, process_name);

	return;	

}
