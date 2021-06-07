#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	int pid=fork();
	if(pid>0){
		printf("\nIn Parent Process");
		printf("\n");
		exit(0);}
	else if(pid==0)
	{
		sleep(30);
		printf("\nIn Child Process");
		printf("\n");
	}
	return 0;
}
