#include <stdio.h>
#include <stdlib.h>
#include <string .h>
#include <sys/types.h>
#include <sys/walt.h>
#include <unistd.h>
#include <errno.h>
#include <sched.h>
#include <time.h>
int main(){
        int pid1, pidz, pid3:
        int с1, с2, с3:
        struct timespec start, stop1, stop2, stop3;
        int t1, t2, t3, t4:
        t1 = clock_gettime(CLOCK_REALTIME, &start);
        c1 = fork():
        if (c1 == 0) {
                struct sched param param1;
                paran1.schod_priority = 3;
                sched_setscheduler(pid1, SCHED_RR, &param1);
                execl("/bin/sh", "sh", "-c", "osbash1.sh", (char*)NULL);
        }
        c2 = fork();
        if (с2 = 0){
            struct sched_param param2:
            param2.sched_priority = 3:
            sched_setscheduler(pid2, SCHED_FIFO, &param2);
            execl("/bin/sh", "sh", "-c", "osbash2.sh", (char*)NULL);
        }
        c3 = fork();
        if (с3 = 0){
            struct sched_param param3:
            param2.sched_priority = 0:
            sched_setscheduler(pid3, SCHED_OTHER, &param3);
            execl("/bin/sh", "sh", "-c", "osbash3.sh", (char*)NULL);
        }
        double aa1, aa2, aa3;
        int wt = waitpid(-1, NULL, 0);
        if (wt == c1){
            int t2 = clock_gettime(CLOCK_REALTIME, &stop1);
            int timerr = stop1.tv_sec - start.tv_sec;
            double timerr2 = stop1.tv_nsec - start.tv_nsec;
            aa1 = (double) timerr;
            aa1 = aa1+ timerr2/((double) 1000000000);
            printf("First working- rr\n");
            printf("%lf\n", aa1);
        }
        else if (wt == c2){
            int t3 = clock_gettime(CLOCK_REALTIME, &stop2);
            int timefifo = stop2.tv_sec - start.tv_sec;
            double timefifo2 = stop2.tv_nsec - start.tv_nsec;
            aa2 = (double) timefifo;
            aa2 = aa2+ timefifo2/((double) 1000000000);
            printf("First working- fifo\n");
            printf("%lf\n", aa2);
        }
        else if (wt == c3){
            int t4 = clock_gettime(CLOCK_REALTIME, &stop3);
            int timeother = stop3.tv_sec - start.tv_sec;
            double timeother2 = stop3.tv_nsec - start.tv_nsec;
            aa3 = (double) timeother;
            aa3 = aa3+ timeother2/((double) 1000000000);
            printf("First working- other\n");
            printf("%lf\n", aa3);
        }
        int wt1 = waitpid(-1, NULL, 0);
        if (wt1 == c1){
            int t2 = clock_gettime(CLOCK_REALTIME, &stop1);
            int timerr = stop1.tv_sec - start.tv_sec;
            double timerr2 = stop1.tv_nsec - start.tv_nsec;
            aa1 = (double) timerr;
            aa1 = aa1+ timerr2/((double) 1000000000);
            printf("Second working- rr\n");
            printf("%lf\n", aa1);
        }
        else if (wt1 == c2){
            int t3 = clock_gettime(CLOCK_REALTIME, &stop2);
            int timefifo = stop2.tv_sec - start.tv_sec;
            double timefifo2 = stop2.tv_nsec - start.tv_nsec;
            aa2 = (double) timefifo;
            aa2 = aa2+ timefifo2/((double) 1000000000);
            printf("Second working- fifo\n");
            printf("%lf\n", aa2);
        }
        else if (wt1 == c3){
            int t4 = clock_gettime(CLOCK_REALTIME, &stop3);
            int timeother = stop3.tv_sec - start.tv_sec;
            double timeother2 = stop3.tv_nsec - start.tv_nsec;
            aa3 = (double) timeother;
            aa3 = aa3+ timeother2/((double) 1000000000);
            printf("Second working- other\n");
            printf("%lf\n", aa3);
        }
        int wt2 = waitpid(-1, NULL, 0);
        if (wt2 == c1){
            int t2 = clock_gettime(CLOCK_REALTIME, &stop1);
            int timerr = stop1.tv_sec - start.tv_sec;
            double timerr2 = stop1.tv_nsec - start.tv_nsec;
            aa1 = (double) timerr;
            aa1 = aa1+ timerr2/((double) 1000000000);
            printf("Third working- rr\n");
            printf("%lf\n", aa1);
        }
        else if (wt2 == c2){
            int t3 = clock_gettime(CLOCK_REALTIME, &stop2);
            int timefifo = stop2.tv_sec - start.tv_sec;
            double timefifo2 = stop2.tv_nsec - start.tv_nsec;
            aa2 = (double) timefifo;
            aa2 = aa2+ timefifo2/((double) 1000000000);
            printf("Third working- fifo\n");
            printf("%lf\n", aa2);
        }
        else if (wt2 == c3){
            int t4 = clock_gettime(CLOCK_REALTIME, &stop3);
            int timeother = stop3.tv_sec - start.tv_sec;
            double timeother2 = stop3.tv_nsec - start.tv_nsec;
            aa3 = (double) timeother;
            aa3 = aa3+ timeother2/((double) 1000000000);
            printf("Third working- other\n");
            printf("%lf\n", aa3);
        }
        printf("%lf %lf %lf\n", aa1, aa2, aa3);
        FILE* output = NULL;
        output = fopen("outputs.txt", "w");
        if (output == NULL){
            exit(EXIT_FAILURE);
        }
        fprintf(output, "%lf %lf %lf", aa1, aa2, aa3);
    }
