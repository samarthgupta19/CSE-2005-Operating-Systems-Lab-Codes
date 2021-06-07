// 19BDS0042 SAMARTH GUPTA

#include<stdio.h>
int i,j,nof,ph,nors,flag=0,ref[50],frm[50],pf=0,victim=-1;
void main()
{	printf("\n\t\t\t  FIFO PAGE REPLACEMENT ALGORITHM");
	printf("\n\t\t\t  -------------------------------");
	printf("\n\nEnter No. of Frames : "); 
	scanf("%d",&nof);
	printf("\nEnter Number of Reference Pages : ");
	scanf("%d",&nors);
	printf("\nEnter The Reference Pages : ");
	for(i=0;i<nors;i++)
	scanf("%d",&ref[i]);
	printf("\nThe Given Reference Pages Are : ");
	for(i=0;i<nors;i++)
	printf("%4d",ref[i]);
	for(i=1;i<=nof;i++)
	frm[i]=-1; printf("\n");
	for(i=0;i<nors;i++)
	{flag=0;	
	printf("\n\t Reference Page-%d->\t",ref[i]);
	for(j=0;j<nof;j++){	
	if(frm[j]==ref[i])
	{    flag=1;  
	     break;      }}
	if(flag==0)  {
	   pf++; victim++;
	   victim=victim%nof;
           frm[victim]=ref[i];
	   for(j=0;j<nof;j++)
	   printf("%4d",frm[j]);}}
ph=nors-pf;
printf("\n\n\t Total Page Hit : %d",ph);
printf("\n\t Total Page Fault : %d\n",pf);
}
