#include<stdio.h>
#include<string.h>

struct process{
    char pname[20];
    int at,bt,wt,tt,status;
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

    //gantt chart reading
    int pno = 0;
    int time = 0;
    int cno = 0;

    while(pno < n) {
        if(time < p[pno].at) {
            int idletime = 0;

            while(time < p[pno].at) {
                time++; 
                idletime++;
            }

            if(cno == 0)
                g[cno].st = 0;
            else
                g[cno].st = g[cno - 1].ct;

            g[cno].ct = g[cno].st + idletime;
            strcpy(g[cno].name,"I");
        } else {

            if(cno == 0)
                g[cno].st = 0;
            else
                g[cno].st = g[cno - 1].ct;

            g[cno].ct = p[pno].bt + g[cno].st; 
            time = time + p[pno].bt;

            p[pno].tt = g[cno].ct - p[pno].at;
            p[pno].wt = p[pno].tt - p[pno].bt;
            strcpy(g[cno].name,p[pno].pname);

            pno++;
        }
        cno++;
    }

    //gantt printing
    printf(" ");
    for(int i = 0; i <= time; i++)
        printf("-");
    printf("\n ");

    for(int i = 0; i < cno; i++) {
        printf("|%s",g[i].name);
        for(int j = 0; j < g[i].ct - g[i].st - 2; j++) {    
            printf(" ");
        }
    }
    printf("|\n ");

    for(int i = 0; i <= time; i++)
        printf("-");

    printf("\n0");
    for(int i = 0; i < cno; i++) {
        for(int j = g[i].st; j < g[i].ct - 1; j++) {
            printf(" ");
        }
        printf("%d",g[i].ct);
    }

    // waiting and turn around time
    int sumwt = 0;
    int sumtt = 0;

    for(int i = 0; i < pno; i++) {
        sumwt = sumwt + p[i].wt;
        sumtt = sumtt + p[i].tt;
    }

    printf("\nAverage Waiting time = %d\nAverage Turn-Around time = %d",sumwt/n,sumtt/n);

    return 0;
}