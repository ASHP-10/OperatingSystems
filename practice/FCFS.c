#include<stdio.h>
#include<string.h>

struct process{
    char name[5];
    int at, bt, wt, tt;
}p[10];

struct gantt{
    char name[5];
    int ct,st;
}g[10];

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    //reading process
    for(int i = 0; i < n; i++) {
        printf("Enter the process name: ");
        scanf("%s",p[i].name);

        printf("Enter the arrival time: ");
        scanf("%d",&p[i].at);

        printf("Enter the burst time: ");
        scanf("%d",&p[i].bt);
    }

    //sorting
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(p[j].at > p[j + 1].at) {
                int temp = p[j + 1].at;
                p[j + 1].at = p[j].at;
                p[j].at = temp;
            }
        }
    }

    //gantt chart reading
    int pno = 0;
    int time = 0;
    int cno = 0;

    while(pno < n) {
        if(p[pno].at > time) {
            int idletime = 0;
            while(p[pno].at > time) {
                time++;
                idletime++;
            }

            if(cno == 0)
                g[cno].st = 0;
            else
                g[cno].st = g[cno - 1].ct;

            g[cno].ct = g[cno].st + idletime;
            strcpy(g[cno].name,"Idle");
        } else {
            if(cno == 0)
                g[cno].st = 0;
            else
                g[cno].st = g[cno - 1].ct;

            g[cno].ct = g[cno].st + p[pno].bt;
            time += p[pno].bt;
            strcpy(g[cno].name,p[pno].name);
            pno++;
        }
        cno++;
    }

    //printing
    printf("\n");

    for(int i = 0; i < cno; i++) {
        printf("_________");
    } printf("\n");

    for(int i = 0; i < cno; i++) {
        printf("|%s\t",g[i].name);
    } printf("\n\n");

    for(int i = 0; i < cno; i++) {
        printf("_________");
    } printf("\n");

    for(int i = 0; i < cno; i++) {
        printf("%d\t",g[i].st);
    } printf("%d",g[cno].ct);

    return 0;
}