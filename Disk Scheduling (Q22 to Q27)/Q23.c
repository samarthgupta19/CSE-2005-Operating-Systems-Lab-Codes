// 19BDS0042 SAMARTH GUPTA

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct request
{	int request_track_number;
	bool visited;
};
int main()
{		int i,no_of_requests,initial_head,max,limit,j,choice,previous_head;
	printf("Enter The Max Range of Disk : ");scanf("%d",&max);printf("\n");
	printf("Enter The Size of Request Queue : ");
	scanf("%d",&no_of_requests);printf("\n");
	struct request req[no_of_requests];
	printf("Enter The Request Queue : ");
	for (i = 0; i < no_of_requests; ++i)
	{
		scanf("%d",&req[i].request_track_number);
		req[i].visited = false;
	}printf("\n");
	printf("Enter Current Head Position : ");
	scanf("%d",&initial_head);
	int seek_time=0;printf("\n");
	printf("Seek Sequence\n");
	printf("-------------\n");
	printf("%d -> ",initial_head );
	int n = no_of_requests;
	while(n)
	{
		int min = 1e9;
		int min_track_number, position;
		for(i=0;i<no_of_requests;i++)
		{
			if(abs(initial_head - req[i].request_track_number) < min && req[i].visited == false)
			{
				min = abs(initial_head - req[i].request_track_number);
				min_track_number = req[i].request_track_number;
				position = i;
			}
		}
		initial_head = req[position].request_track_number;
		req[position].visited = true;
		printf("%d ->",min_track_number);
		seek_time += min;
		n--;	}printf("\n");
	printf("\nTotal Seek Time = %d\n", seek_time);
}
