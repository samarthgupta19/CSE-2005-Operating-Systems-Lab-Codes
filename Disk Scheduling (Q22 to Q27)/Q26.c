#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void merge(int a[],int low,int mid,int high)
{int i=low,j=mid+1,k=low,c[high+1];
        while(i<=mid&&j<=high)	    {
		    if(a[i]<=a[j]){
				    c[k]=a[i];   i++;
				    k++; }
				    else{
				   c[k]=a[j];
				    j++;   k++;
				    }}
	while(i<=mid)
	{	c[k]=a[i];
		i++;	k++;
	}
	while(j<=high)
	{c[k]=a[j];j++;
	k++;}
	for(i=low;i<high+1;i++)
	a[i]=c[i];}
void ms(int a[],int low,int high)
{	int mid;
	if(low<high)	{
		mid=(low+high)/2;
		ms(a,low,mid);
		ms(a,mid+1,high);
		merge(a,low,mid,high);}}
void main()
{	int i,j=0,n,max;printf("\n");
	printf("Enter The Max Range of Disk : ");
	scanf("%d",&max);printf("\n");
	printf("Enter The Size Of Request Queue : ");
	scanf("%d",&n);printf("\n");
	int Rq[n],curr,choice=0;
	printf("Enter The Request Queue : \n");
	for(i=0;i<n;i++)
		scanf("%d",&Rq[i]);
	ms(Rq,0,n-1);
	printf("\n"); printf("Enter Current Head Position : ");
	scanf("%d",&curr);
	int track_mom[n]; printf("\n");
	printf("Choose Direction :\n1. Left\t 2. Right\nEnter Choice : ");
	scanf("%d",&choice);printf("\n");
	printf("\nSeek Sequence\t\tTrack Movements\n");
	printf("---------------\t\t---------------\n");
	while(Rq[j]<curr)
		j++;
	switch(choice)
	{case 1:
			for(i=j-1;i>=0;i--){
				track_mom[i]=abs(Rq[i]);	
				printf("%d<->%d   \t\t%d\n",curr,Rq[i],track_mom[i]);
		        	curr=Rq[i];}
			for(i=j;i<n;i++){
				track_mom[i]=abs(Rq[i]-curr);
				printf("%d<->%d   \t\t%d\n",curr,Rq[i],track_mom[i]);
				curr=Rq[i];
			}	break;
		default:
			for(i=j;i<n;i++){
				track_mom[i]=abs(Rq[i]-curr);
				printf("%d<->%d   \t\t%d\n",curr,Rq[i],track_mom[i]);
				curr=Rq[i];}
			for(i=j-1;i>=0;i--)
			{	track_mom[i]=abs(Rq[i]-curr);
				printf("%d<->%d   \t\t%d\n",curr,Rq[i],track_mom[i]);
				curr=Rq[i];
			}break;}
	int sum=0;
	for(i=0;i<n;i++)
		sum+=track_mom[i];
	printf("\n");
	printf("Total Head Movements (No. of Cylinders) = %d",sum);printf("\n");
}

