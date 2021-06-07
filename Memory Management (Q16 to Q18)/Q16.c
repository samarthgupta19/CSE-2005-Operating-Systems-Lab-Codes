// 19BDS0042 SAMARTH GUPTA

#include<stdio.h>
#define max 25
void main()
{
	int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0;
	static int bf[max],ff[max];int flag,flagn[max],fragi = 0,fragx = 0;
	printf("\nEnter The Number of Blocks : ");
	scanf("%d",&nb);
	printf("Enter The Number of Process : ");
	scanf("%d",&nf);
	printf("\nEnter The Size of The Blocks : \n");
	for(i=1;i<=nb;i++) {
		printf("Block %d : ",i);
		scanf("%d",&b[i]);
		ff[i] = i;
	}
	printf("\nEnter The Size of The Processes : \n");
	for(i=1;i<=nf;i++) {
		printf("Process %d : ",i);
		scanf("%d",&f[i]);	}
	int x = 1;
	printf("\n\nProcess_No.\tProcess_Size\tBlock_No.\tBlock_Size\tBlock_Size_Left\n");
	for(i=1;i<=nf;i++)
	{
		flag = 1;
		for(j=x;j<=nb;j++){
			if(f[i] <= b[j]){
				flagn[j] = 1;
				printf("%-15d\t%-15d\t%-15d\t%-15d\t",i, f[i],ff[j],b[j]);
				b[j] = b[j] - f[i];
				fragi = fragi + b[j];
				printf("%-15d\n",b[j]);
				break;}
			else
			{flagn[j] = 0;
				x = 1;
  			flag++;
			}
		}if(flag > nb)
			printf("%-15d\t%-15d\t%-15s\t%-15s\t%-15s\n",i, f[i],"WAIT","WAIT","WAIT");
	}
}
