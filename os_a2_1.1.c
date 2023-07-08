#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <errno.h>
#include <stdio.h>
// #include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

void *countA(){
    for(long long int i = 0; i < pow(2, 32); i++){
        int v = 1;
    }
    struct timespec tp;struct sched_param sp;
    int c1 = clock_gettime(CLOCK_REALTIME, &tp);int polic;
    int us = pthread_getschedparam (pthread_self(), &polic, &sp);
    sp.sched_priority = 56;
    pthread_setschedparam(pthread_self(), SCHED_RR, &sp);
    printf("c1 = %ld\n", tp.tv_sec);
    printf("priority = %d\n", sched1.sched_priority);
}
void *countB(){
    for(long long int i = 0; i < pow(2, 32); i++){
        int v = 1;
    }
    struct timespec tp;struct sched_param sp;
    int c2 = clock_gettime(CLOCK_REALTIME, &tp);int polic;
    int us = pthread_getschedparam (pthread_self(), &polic, &sp);
    sp.sched_priority = 44;
    pthread_setschedparam(pthread_self(), SCHED_FIFO, &sp);
    printf("c2 = %ld\n", tp.tv_sec);
    printf("priority = %d\n", sp.sched_priority);
}
void *countC(){
    for(long long int i = 0; i < pow(2, 32); i++){
        int v = 1;
    }
    struct timespec tp;struct sched_param sp;
    int c3 = clock_gettime(CLOCK_REALTIME, &tp);int polic;
    int us = pthread_getschedparam (pthread_self(), &polic, &sp);
    sp.sched_priority = 0;
    pthread_setschedparam(pthread_self(), SCHED_OTHER, &sp);
    printf("c3 = %ld\n", tp.tv_sec);
    printf("priority = %d\n", sp.sched_priority);
}
int main(){
    struct timespec start, stop, tp, t, u, v, w;pthread_t thread1,thread2,thread3;pthread_attr_t attr1,attr2, attr3;

    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    pthread_attr_init(&attr3);

    int sched_rr_min=sched_get_priority_min(SCHED_RR);
    int sched_rr_max=sched_get_priority_max(SCHED_RR);

    printf("RR min = %d\t", sched_rr_min);
    printf("RR max = %d\n", sched_rr_max);

    int sched_fifo_min=sched_get_priority_min(SCHED_FIFO);
    int sched_fifo_max=sched_get_priority_max(SCHED_FIFO);

    printf("FIFO min= %d\t", sched_fifo_min);
    printf("FIFO max= %d\n", sched_fifo_max);

    int sched_other_min=sched_get_priority_min(SCHED_OTHER);
    int sched_other_max=sched_get_priority_max(SCHED_OTHER);

    printf("OTHER max= %d\t", sched_other_min);
    printf("OTHER min= %d\n", sched_other_max);
    pthread_attr_setschedpolicy(&attr1, SCHED_RR);
    pthread_attr_setschedpolicy(&attr2, SCHED_FIFO);
    pthread_attr_setschedpolicy(&attr3, SCHED_OTHER);
    for(int i = 0; i < 10; i++){int c0 = clock_gettime( CLOCK_REALTIME, &start);
    int thrA = pthread_create(&thread1,&attr1, &countA, NULL);
    pthread_join(thread1, NULL);
    int c4 = clock_gettime( CLOCK_REALTIME, &stop);     // equals time in countA
    int thrB = pthread_create(&thread2,&attr2, &countB, NULL);
    pthread_join(thread2, NULL);
    int c5 = clock_gettime( CLOCK_REALTIME, &tp);       // equals time in countB
    int thrC = pthread_create(&thread3,&attr3, &countC, NULL);
    pthread_join(thread3, NULL);
    int c6 = clock_gettime( CLOCK_REALTIME, &t);       // equals time in countC
    
    // stop-start to get time of running
    printf("time for pthread1 = %ld sec\n", stop.tv_sec - start.tv_sec);
    printf("time for pthread2 = %ld sec\n", tp.tv_sec - stop.tv_sec);
    printf("time for pthread3 = %ld sec\n", t.tv_sec - tp.tv_sec);
    //file for opening histogram
    FILE *fp = NULL;
    fp = fopen("outputs.txt", "w");
    if(fp == NULL){
        exit(EXIT_FAILURE);
    }
    frpintf(fp, "%lf %lf %lf\n", stop.tv_sec - start.tv_sec, tp.tv_sec - stop.tv_sec, t.tv_sec - tp.tv_sec);}
}