#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
sem_t x,y;
pthread_t tid;
pthread_t writerthreads[100],readerthreads[100];
int readercount = 0;
void *reader(void* param)
{	sem_wait(&x); readercount++;
	if(readercount==1) sem_wait(&y);
	sem_post(&x);
	printf("Reader No. %d Is Inside\n",readercount);
	usleep(3);
	sem_wait(&x);
	readercount--;
	if(readercount==0)
	{ sem_post(&y);}
	sem_post(&x);
	printf("Reader No. %d Is Leaving\n",readercount+1);
	return NULL;}
void *writer(void* param)
{	printf("Writer Is Trying To Enter\n");
	sem_wait(&y);
	printf("Writer Has Entered\n");
	sem_post(&y);
	printf("Writer Is Leaving\n");
	return NULL;}
int main()
{	int n2,i;
	printf("Enter The Number of Readers : ");
	scanf("%d",&n2);
	printf("\n");
	int n1[n2];
	sem_init(&x,0,1);
	sem_init(&y,0,1);
	for(i=0;i<n2;i++)
	{	pthread_create(&writerthreads[i],NULL,reader,NULL);
		pthread_create(&readerthreads[i],NULL,writer,NULL);
	}
	for(i=0;i<n2;i++)
	{	pthread_join(writerthreads[i],NULL);
		pthread_join(readerthreads[i],NULL);
	}
}


