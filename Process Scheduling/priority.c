#include<stdio.h>
#include<string.h>

struct process{
    char pname[20];
    int at,bt,wt,tt, status, priority;
}p[20],temp;

struct gantt{
    char name[29];
    int st,ct;
}g[20];

int main() {

    int n;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    //reading process
    for(int i = 0; i < n; i++) {
        printf("Enter the process name: ");
        scanf("%s",p[i].pname);

        printf("Enter the arrival time: ");
        scanf("%d",&p[i].at);

        printf("Enter the burst time: ");
        scanf("%d",&p[i].bt);

        printf("Enter the priority: ");
        scanf("%d", &p[i].priority);
    }

    //sorting based on arrival time
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(p[j].at > p[j+1].at) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    int pno = 0;
    int time = 0;
    int cno = 0;

    while(pno < n) {
        if(cno == 0)
            g[cno].st = 0;
        else
            g[cno].st = g[cno - 1].ct;

        if(p[pno].at > time) {
            int idletime = 0;

            while(p[pno].at > time) {
                time++;
                idletime++;
            }

            g[cno].ct = g[cno].st + idletime;
            strcpy(g[cno].name, "I");
        } else {
            int maxP = -1;
            int maxPriority = __INT_MAX__;

            for(int i = 0; i < n; i++) {
                if(p[i].at <= time && p[i].status == 0 && p[i].priority < maxPriority) {
                    maxP = i;
                    maxPriority = p[i].priority;
                }
            }

            g[cno].ct = g[cno].st + p[maxP].bt;
            time += p[maxP].bt;
            strcpy(g[cno].name, p[maxP].pname);
            p[maxP].status = 1;
            pno++;
        }
        cno++;
    }

    for(int i = 0; i < cno; i++)
        printf("-------");
    printf("\n");

    for(int i = 0; i < cno; i++)
        printf("|%s     ",g[i].name);
    printf("\n");

    for(int i = 0; i < cno; i++) 
        printf("-------");
    printf("\n0       ");

    for(int i = 0; i < cno; i++)
        printf("%d      ",g[i].ct);

    return 0;
}