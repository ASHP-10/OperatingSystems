#include<stdio.h>
#include<string.h>
#include<stdbool.h>

struct process{
    char name[5];
    int allocation[5];
    int max[5];
    int need[5];
    bool issafe;
}p[10];

int available[5],n,I;

int main() {
    int size;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    printf("Enter the number of instances: ");
    scanf("%d",&I);

    for(int i = 0; i < n; i++) {
        printf("Enter the process number: ");
        scanf("%s",p[i].name);

        p[i].issafe = false;
        for(int j = 0; j < I; j++) {
            printf("Enter thr resource allocated for instance %d of process %s",j,p[i].name);
            scanf("%d",&p[i].allocation[j]);

            printf("Enter thr maximum resource allocated for instance %d of process %s",j,p[i].name);
            scanf("%d",&p[i].max[j]);
        }
    }

    for(int i = 0; i < I; i++) {
        printf("Enter the available for instance %d: ",i);
        scanf("%d",&available[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < I; j++) {
            p[i].need[j] = p[i].max[j] - p[i].allocation[j];
        }
    }

    int pno = 0;
    bool flag;
    char safeseq[5][5], ss = 0;
    bool breaksafe = false;
    bool breaknotsafe = false;

    do{
        if(!p[pno].issafe) {
            flag = true;
            for(int i = 0; i < n; i++) {
                if(p[pno].need[i] > p[pno].allocation[i]) {
                    flag = false;
                    break;
                }
            }
        }

        if(flag) {
            for(int i = 0; i < I; i++) {
                available[i] += p[pno].allocation[i];
            }
            p[pno].issafe = true;
            strcpy(safeseq[ss++], p[pno++].name);
        }

        //exit condition
        breaksafe = true;
        breaknotsafe = true;
        int safecount = 0;
        int prevcount = 0;

        for(int i = 0; i < n; i++) {
            if(!p[i].issafe) {
                breaksafe = false;
                break;
            } else {
                safecount++;
            }
        }

        if(prevcount == safecount) {
            breaknotsafe = true; 
        } else {
            prevcount = safecount;
        }

        pno++;

    }while(!breaksafe && breaknotsafe);

    if(breaksafe) {
        printf("The safe sequence is <");
        for(int i = 0; i <= ss; i++) {
            printf("%s, ",safeseq[i]);
        } printf(">");
    } else {
        printf("System is not in safe state");
    }

    return 0;
}