#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct process{
    char pname[20];
    bool issafe;
    int allocation[20];
    int need[20];
    int max[20];
}p[10];

int main()
{
    int n;
    int I;

    printf("Enter the number of process: ");
    scanf("%d",&n);

    printf("Enter number of allocations for each proc   ess: ");
    scanf("%d",&I);

    int available[I];

    for(int i = 0; i < n; i++) {
        printf("Enter the process name: ");
        scanf("%s", p[i].pname);

        p[i].issafe = false;

        for(int j = 0, k = 65; j < I; j++, k++) {
            printf("Enter the resource of allocation %c: ", k);
            scanf("%d",&p[i].allocation[j]);

            printf("Enter the max of allocation %c",k);
            scanf("%d",&p[i].max[j]);
        }
    }

    for(int i = 0; i < I; i++) {
        printf("Enter the number of available resource for: ");
        scanf("%d",&available[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < I; j++) {
            p[i].need[j] = p[i].max[j] - p[i].allocation[j];
        }
    }

    // print table
    printf("\n\t\tAllocation Table\t\t\n");
    printf("Process\t\tAllocation\tMax\t\tNeed\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t", p[i].pname);

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
    int ss = 0;
    char safqSeq[20][n];
    int pi = 0;

    do {
        if(!p[pi % n].issafe) {
            flag = true;
            for(int i = 0; i < I; i++) {
                if(p[pi % n].need[i] > available[i]) {
                    flag = false;
                    break;
                }
            }
        }

        if(flag) {
            for(int i = 0; i < I; i++) {
                available[i] += p[pi % n].allocation[i];
            }
            p[pi % n].issafe = true;
            strcpy(safqSeq[ss++], p[pi % n].pname);
        }

        pi++;

        if(pi >= 100) break;
    } while(ss < n);

    if(ss == n) {
        for(int i = 0; i < ss; i++) 
            printf("<%s,", safqSeq[i]);
    } else 
        printf("Not in safe state");

    int ch;

    printf("Request? 1 for yes\n 2 for no");
    scanf("%d",&ch);

    if(ch == 1) {
        char name[20];

        printf("Enter the process that that needs to request: ");
        scanf("%s",name);

        int req[I];
        printf("Enter the requested resource: ");
        for(int i = 0; i < I; i++) {
            scanf("%d",req[i]);
        }

        for(int i = 0; i < n; i++) {
            int flagAva;

            if(strcmp(name, p[i].pname) == 0) {
                flagAva = 0;
                for(int j = 0; j < I; j++) {
                    if(req[j] <= available[i])
                        flagAva++;
                }
            }
        

            if(flagAva == I) {
                
            }
        }
    }
    return 0;
} 