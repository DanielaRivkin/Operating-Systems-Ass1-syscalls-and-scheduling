#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[]) 
{
    int proc1;
    int proc2;
    int proc3;
    int pid;
    int rtime;
    int cfs_priority;
    int retime;
    int stime;

    if( (proc1 = fork()) == 0){ 
        if( (proc2 = fork()) == 0){ 
            if((proc3 = fork()) == 0){
                set_cfs_priority(0);
                for (int i = 0; i < 1000000; i++)
                {
                    if(i % 100000 == 0 && i != 0)
                        sleep(10);
                }
                pid = getpid();
                get_cfs_stats(pid, &cfs_priority, &stime, &rtime, &retime);
                printf("pid:%d priority:%d rtime:%l stime:%l retime:%l\n", getpid(), cfs_priority,rtime, stime,retime);
                exit(0, "");
            }
            else{ 
            set_cfs_priority(1);
            for (int i = 0; i < 1000000; i++)
            {
                if(i % 100000 == 0 && i != 0)
                    sleep(10);
            }
            wait(&proc3,"");
            pid = getpid();
            get_cfs_stats(pid, &cfs_priority, &stime, &rtime, &retime);
            printf("pid:%d priority:%d rtime:%l stime:%l retime:%l\n", getpid(), cfs_priority,rtime, stime,retime);
            exit(0, "");
            }
        }
        else{ 
            set_cfs_priority(2);
            for (int i = 0; i < 1000000; i++)
            {
                if(i % 100000 == 0 && i != 0)
                    sleep(10);
            }
            wait(&proc2,"");
            pid = getpid();
            get_cfs_stats(pid, &cfs_priority, &stime, &rtime, &retime);
            printf("pid:%d priority:%d rtime:%l stime:%l retime:%l\n", getpid(), cfs_priority,rtime, stime,retime);
            exit(0, "");
        }
    }

    else{ 
        wait(&proc1,"");
        printf("finished\n");
    }

    exit(0, "");
}