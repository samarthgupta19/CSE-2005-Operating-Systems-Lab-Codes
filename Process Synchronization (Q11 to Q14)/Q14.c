// 19BDS0042 SAMARTH GUPTA

#define _XOPEN_SOURCE 500
#define _REENTRANT
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "chopsticks.h"
pthread_mutex_t outlock; /* protects against output interleaving */
int nsteps, maxsteps = 0; /* number of steps to run this test */
int eat_count[NTHREADS]; /* number of steps for each thread */
void trace(int i, char *s) {
/* print out message, for use in execution tracing
i = philospher ID
s = message */
pthread_mutex_lock(&outlock);
if (strcmp (s, "eating") == 0) eat_count [i]++;
/*fprintf(stdout,"%d: %s\n",i,s); */
if (nsteps++ > maxsteps) {
/* don't exit while we are holding any chopsticks */
if (strcmp(s,"thinking") == 0) {
pthread_mutex_unlock(&outlock);
/*fprintf (stderr, "thread done\n");*/
pthread_exit(0);
}}pthread_mutex_unlock(&outlock);
}void * philosopher_body(void *arg) {
int self = *(int *) arg;
for (;;) {
trace(self,"thinking");
chopsticks_take(self);
trace(self,"eating");
chopsticks_put(self);
}
}int main() {
int i;
pthread_t th[NTHREADS]; /* IDs of the philospher threads */
int no[NTHREADS]; /* corresponding table position numbers*/
pthread_attr_t attr;
for (i = 0; i < NTHREADS; i++) eat_count [i] = 0;
pthread_mutex_init(&outlock, NULL);
/* initialize the object chopsticks */
chopsticks_init();
fprintf(stdout,"enter number of steps to run: "); fflush(stdout);
fscanf(stdin,"%d",&maxsteps);
pthread_attr_init (&attr); /* sets default attributes */
pthread_setconcurrency (4);
/* suggest four kernel threads for this process */
pthread_attr_setscope (&attr, PTHREAD_SCOPE_SYSTEM);
/* set system-wide contention scope */
/* start up the philosopher threads */
for (i = 0; i < NTHREADS; i++) {
no[i] = i;
pthread_create(&th[i], NULL, philosopher_body, (int *) &no[i]);
}/* wait for all the threads to shut down */
for (i = 0; i < NTHREADS; i++) pthread_join(th[i], NULL);
for (i = 0; i < NTHREADS; i++) {
fprintf (stderr, "philospher %d ate %d times\n", i, eat_count [i]); }
return 0;
}
