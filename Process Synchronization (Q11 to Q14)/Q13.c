// 19BDS0042 SAMARTH GUPTA

#include<stdlib.h>
#include<stdio.h>
int chopstick[5]={1,1,1,1,1};
void eating(); int wait(int);
int signal(int);
int main(){
	int n; char ch;
	while(1){printf("\n\tMAIN MENU");
		printf("\n\t*********");
		printf("\n\n1. For Eating   2. Exit\n\n");
		printf("Enter Choice : ");
		scanf("%d",&n);
		switch(n){
		case 1: eating();
			break;
		case 2: exit(1); }}
return 0;}
int wait(int s){
	--s; return s;}
int signal(int s){
	++s; return s;}
void eating(){
	int phil,n;
	printf("\nWhich Philosopher Wants To Eat ? : ");
	scanf("%d",&phil);
	if(chopstick[phil-1]==1 && chopstick[phil]==1){
		chopstick[phil-1]=wait(chopstick[phil-1]);
		chopstick[phil]=wait(chopstick[phil]%5);
		printf("\nPhilosopher %d Is Eating...\n",phil);
xy:
		printf("\n1. Feed Another Philosopher   2. Stop Feeding Current Philosopher");
		printf("\n\nEnter Choice : ");
		scanf("%d",&n);
		if(n==1){
			eating(); goto xy; }
		else{   chopstick[phil-1]=signal(chopstick[phil-1]);
			chopstick[phil]=signal(chopstick[phil]%5);
			printf("\nPhilosopher %d Is Done Eating\n",phil);}
} else{	printf("\nChopsticks Are Not Available.\n");
	return;}
}
