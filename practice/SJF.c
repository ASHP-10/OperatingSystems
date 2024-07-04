#include<stdio.h>
#include<string.h>

struct process{
    char name[10];
    int at,bt,tt,wt,status;
}p[10];

struct gantt{
    char process[5];
    int ct,st;
}g[10];

int n;
int get_min(int time);

int main() {

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
        
        p[i].status = 0;
    }

    //sorting based on arrival time
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(p[j].at > p[j+1].at) {
                int temp = p[j + 1].at;
                p[j + 1].at = p[j].at;
                p[j].at = temp;
            }
        }
    }

    //gantt cahrt reading
    int pno = 0;
    int cno = 0;
    int time = 0;
    while(pno < n) {
        if(p[pno].at > time) {
            int idletime = 0;

            while(p[pno].at > time) {
                idletime++;
                time++;
            }

            if(cno == 0)
                g[cno].st = 0;
            else
                g[cno].st = g[cno - 1].ct;

            g[cno].ct = g[cno].st + idletime;
            strcpy(g[cno].process,"IDLE");                       
        } else {
            int min = get_min(time);

            if(min == -1) {
                time++;
                continue;
            }

            if(cno == 0)
                g[cno].st = 0;
            else
                g[cno].st = g[cno - 1].ct;

            g[cno].ct = g[cno].st + p[min].bt;
            time += p[min].bt;

            strcpy(g[cno].process,p[min].name);
            p[min].status = 1;

            pno++;
        }
        cno++;
    }

    //gantt chart printing
    printf("\n\n");
    for(int i = 0; i < cno; i++) {
        printf("--");
    } printf("\n");

    for(int i = 0; i < cno; i++) {
        printf("|%s\t",g[i].process);
    } printf("|\n");

    for(int i = 0; i < cno; i++) {
        printf("--");
    } printf("\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t",g[i].st);
    } printf("%d",g[cno].ct);
    

    return 0;
}

int get_min(int time) {
    int min = -1;
    
    for(int i = 0; i < n; i++) {
        if(p[i].status == 0 && time >= p[i].at && (min = -1 || p[min].bt > p[i].bt)) {
            min = i;
        }
    }

    return min;
}