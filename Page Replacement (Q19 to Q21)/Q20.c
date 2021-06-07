#include<stdio.h>
int i,j,nof,nor,flag=0,ref[50],frm[50],pf=0,victim=-1,ph;
int recent[10],lrucal[50],count=0;
int lruvictim();
void main()
{	printf("\n\t\t\t  LRU PAGE REPLACEMENT ALGORITHM");
	printf("\n\t\t\t  ------------------------------");
	printf("\n\nEnter No. of Frames : ");
	scanf("%d",&nof);
	printf("\nEnter No. of Reference Pages : ");
	scanf("%d",&nor);
	printf("\nEnter The Reference Pages : ");
	for(i=0;i<nor;i++) scanf("%d",&ref[i]);
	printf("\nThe Given Reference Pages Are : ");
	for(i=0;i<nor;i++) printf("%4d",ref[i]);
	for(i=1;i<=nof;i++){	frm[i]=-1;
	lrucal[i]=0;}
	for(i=0;i<10;i++) recent[i]=0;
	printf("\n");
	for(i=0;i<nor;i++) {flag=0;
	printf("\n\t Reference Page-%d->\t",ref[i]);
	for(j=0;j<nof;j++)
	{if(frm[j]==ref[i])
		{flag=1;	break;
		}} if(flag==0)
		{	count++;
			if(count<=nof) victim++;
			else victim=lruvictim(); pf++;
			frm[victim]=ref[i];
			for(j=0;j<nof;j++)
			printf("%4d",frm[j]);}
		recent[ref[i]]=i; ph=nor-pf;}
	printf("\n\n\t Total Page Hit : %d",ph);
	printf("\n\t Total Page Fault : %d\n",pf);}
int lruvictim()
{	int i,j,temp1,temp2;
	for(i=0;i<nof;i++)
	{	temp1=frm[i];
		lrucal[i]=recent[temp1];}
	temp2=lrucal[0];
	for(j=1;j<nof;j++)
	{if(temp2>lrucal[j])
	temp2=lrucal[j];
	} for(i=0;i<nof;i++)
	if(ref[temp2]==frm[i])
	return i;return 0;
}
