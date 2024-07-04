#include<stdio.h>
#include<stdbool.h>
#include<string.h>

struct process{
    char name[5];
    int allocation[5];
    int max[5];
    int need[5];
    bool issafe;
}p[10];

int available[5];

int main() {
    int n, I, k;
    bool cmp1[5];
    bool cmp2[5];

    //input
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of instances: ");
    scanf("%d", &I);

    for(int i = 0; i < n; i++) {
        printf("Enter the process name: ");
        scanf("%s",p[i].name);

        p[i].issafe = false;

        for(int j = 0,k = 'A'; j < I; j++, k++) {
            printf("Enter number of instance allocated of the resource %c to the %s: ",k, p[i].name);
            scanf("%d",&p[i].allocation[j]);

            printf("Enter the Maximum demand of resource %c of %s: ",k, p[i].name);
            scanf("%d",&p[i].max[j]);
        }
    }

    for(int i = 0, k = 'A'; i < I; i++, k++){
        printf("Enter the number of available for resource %c: ",k);
        scanf("%d", &available[i]);
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < I; j++) {
            p[i].need[j] = p[i].max[j] - p[i].allocation[j];
        }
    }

    //table printing
    printf("\n\t\tAllocation Table\t\t\n");
    printf("Process\t\tAllocation\tMax\t\tNeed\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t", p[i].name);

        for (int j = 0; j < I; j++) {
            printf("%d ", p[i].allocation[j]);
        }
        printf("\t\t");
    
        for (int j = 0; j < I; j++) {
            printf("%d ", p[i].max[j]);
        }
        printf("\t\t");

        for (int j = 0; j < I; j++) {
            printf("%d ", p[i].need[j]);
        }
        printf("\n");
    }


    bool flag;
    int pi = 0;
    bool breaksafe = false;
    bool breaknotsafe = false;
    int check = 1;
    char safeseq[10][10];
    int ss = 0;

    do{
        //deadlock avoidance
        if(!p[pi].issafe) {
            flag = true;
            for(int i = 0; i < I; i++) {
                if(p[pi].need[i] > available[i]) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                for(int i = 0; i < I; i++) {
                    available[i] += p[pi].allocation[i];
                }
                p[pi].issafe = true;
                strcpy(safeseq[ss++], p[pi].name);
            }
        }


        //exit condition
        //break condition for when all processes are safe

        breaksafe = true;
        int safecount = 0;
        int totalcount = 0;
        int prevcount = 0;

        for(int i = 0; i < n; i++) {
            if(!p[i].issafe) {
                breaksafe = false;   
            } else {
                safecount++;
            }
        }

        //break condition for when deadlock exists
        breaknotsafe = false;
        if(safecount == prevcount) {
            breaknotsafe = true;
        } else {
            prevcount = safecount;
        }
        pi++;
    } while (!breaksafe && breaknotsafe);

    //output
    if(breaksafe) {
        printf("The safe sequence is: <");
        for(int i = 0; i < ss; i++) {
            printf("%s, ",safeseq[i]);
        }
        printf(">");
    } else {
        printf("The system is not in the safe state");
    }

    return 0;
}