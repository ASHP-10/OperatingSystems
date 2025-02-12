#include<stdio.h>
#include<string.h>
#include <stdbool.h>

struct process{
    char pname[20];
    int at,bt,wt,tt,status;
}p[20],temp;

struct gantt{
    char name[29];
    int st,ct;
}g[20];

int get_min(int time);
int n;

int main() {

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

        p[i].status = 0;     //not yet executed
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
    int cno = 0;
    int time = 0;
    
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
            int minbt = __INT_MAX__;
            int minP = 0;
            
            for(int  i = 0; i < n; i++) {
                if(time >= p[i].at) {
                    if(p[i].status == 0 && minbt > p[i].bt) {
                        minP = i;
                        minbt = p[i].bt;
                    }
                } else {
                    break;
                }
            }

            p[minP].status = 1;
            time += p[minP].bt;
            g[cno].ct = g[cno].st + p[minP].bt;
            strcpy(g[cno].name, p[minP].pname);
            pno++;
        }
	cno++;
	}
	
	//gantt printing

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