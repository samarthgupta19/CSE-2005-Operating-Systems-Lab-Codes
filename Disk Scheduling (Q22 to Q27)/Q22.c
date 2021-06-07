#include<stdio.h>
#include<stdlib.h>
int main()
{
	int queue[20],n,head,i,j,k,seek=0,max,diff;
	printf("Enter The Max Range of Disk : \n");
	scanf("%d",&max); printf("\n");
	printf("Enter The Size of Queue Request : \n");
	scanf("%d",&n); printf("\n");
	printf("Enter The Queue of Disk Positions To Be Read : \n");
	for(i=1;i<=n;i++)
		scanf("%d",&queue[i]);
	printf("\n");
	printf("Enter The Initial Head Position : \n");
	scanf("%d",&head);
	queue[0]=head;
	printf("\n");
	for(j=0;j<=n-1;j++)
	{
		diff=abs(queue[j+1]-queue[j]);
		seek+=diff;
		printf("Disk Head Moves From %d to %d With Seek = %d\n",queue[j],queue[j+1],diff);
	}
	printf("\n");
	printf("Total Seek Time : %d\n",seek);
	return 0;
}
