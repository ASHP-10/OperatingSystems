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
        
        p[i].status = 0;
          
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
        
		    int min = get_min(time);
        
            if(min == -1) {
                time++;
                continue;
            }

			if(cno == 0)
		        g[cno].st = 0;
		    else
		        g[cno].st = g[cno - 1].ct;
		          
		    g[cno].ct = p[min].bt + g[cno].st;
		    time = time + p[min].bt;
		      
		    strcpy(g[cno].name,p[min].pname);
		    p[min].status = 1;
		      
		    pno++;
		}
		cno++;
	}
	
	//gantt printing
    cno--;

    for(int i = 0; i < g[cno].ct; i++) {
        printf("___");
    }
    printf("\n");

    for(int i = 0; i < pno; i++) {
        printf("|%s",g[i].name);
        for(int j = 0; j < g[i].ct - strlen(g[i].name); j++) {
            printf(" ");
        }
    }
    printf("|\n");

    for(int i = 0; i < g[cno].ct; i++) {
        printf("---");
    }
    printf("\n");

    for(int i = 0; i < g[cno].ct; i++) {
        printf("%d",g[i].st);
        for(int j = 0; j < g[i].ct - strlen(g[i].name); i++) {
            printf(" ");
        }
    }
}

int get_min (int time){
    int min = -1; 

    for(int i = 0; i < n; i++) {
        if(p[i].status == 0 && time >= p[i].at && (min == -1 || p[min].bt > p[i].bt)) { 
            min = i;
        }
    }

    return min;
}