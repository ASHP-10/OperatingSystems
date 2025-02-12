#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

struct process {
	char pname[20];
	int at, bt, tt, wt, status,remaining;
}p[20], Q[20], temp1, *temp2;

struct chart {
	char name[20];
	int st, ct;
}g[20];

int n, ts;
int front = -1, rear = -1;

struct process deque();
void enque(struct process temp);
bool isempty();

int main() {	
	
	//reading values
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	
	for(int i = 0; i <n; i++) {
		printf("Enter the process name: ");
		scanf("%s",p[i].pname);
		
		printf("Enter the arrival time: ");
		scanf("%d",&p[i].at);
		
		printf("Enter the burst time: ");
		scanf("%d",&p[i].bt);
		
		p[i].status = 0;
		p[i].remaining = p[i].bt;
	}
	
	printf("Enter the time slice: ");
	scanf("%d",&ts);

	//sorting based on arrival time
	for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(p[j].at > p[j+1].at) {
                temp1 = p[j];
                p[j] = p[j+1];
                p[j+1] = temp1;
            }
        }
    }
    
	//gantt chart generation
    int pno = 0;
    int time = 0;
    int cno = 0;
    
    temp2 = (struct process *)malloc(sizeof(struct process));
    //temp2 = NULL;


    while(pno < n || !isempty()) {
        if(time < p[pno].at && isempty()) {
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

			while(p[pno].at <= time && pno < n) {
				enque(p[pno]);
				pno++;
			}

			if (temp2 != NULL && temp2->remaining > 0) {
				enque(*temp2);
			}

			if(cno == 0)
                g[cno].st = 0;
            else
                g[cno].st = g[cno - 1].ct;

			*temp2 = deque();

			if(temp2 -> remaining <= ts) {
				g[cno].ct = g[cno].st + temp2 -> remaining;
				time += temp2 -> remaining;
				temp2 -> remaining = 0;
				temp2 -> status = 1;
				strcpy(g[cno].name, temp2 -> pname);
			} else {
				temp2 -> remaining -= ts;
				g[cno].ct = g[cno].st + ts;
				time += ts;
				strcpy(g[cno].name, temp2 -> pname);
			}

			for(int i = 0; i < pno; i++) {
				if(strcmp(p[i].pname,temp2 -> pname) == 0) {
					p[i] = *temp2;
					break;
				}
			}
		}
		cno++;
	}

	//gantt chart printing
	/*cno--;

    for(int i = 0; i < g[cno].ct; i++) {
        printf("---");
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
        for(int j = 0; j < g[i].ct - strlen(g[i].name); j++) {
            printf(" ");
        }
    }*/
    
    cno--;

    for (int i = 0; i < g[cno].ct; i++) {
        printf("--");
    }
    printf("\n");

    for (int i = 0; i <= cno; i++) {
        printf("|%s", g[i].name);
        for (int j = g[i].ct - strlen(g[i].name) - g[i].st; j > 0; j--) {
            printf(" ");
        }
    }
    printf("|\n");

    for (int i = 0; i < g[cno].ct; i++) {
        printf("--");
    }
    printf("\n");

    for (int i = 0; i <= cno; i++) {
        printf("%d", g[i].st);
        for (int j = g[i].ct - g[i].st; j > 0; j--) {
            printf(" ");
        }
    } printf("%d",g[cno].ct);
}

struct process deque() {
	struct process temp;
	if(isempty()) {
		printf("Queue is empty");
		return temp;
	}
	
	temp = Q[front];

	if(front == rear) {
		front = -1;
		rear = -1;
	} else {
		front++;
	}
	
	return temp;
	
}

void enque(struct process temp) {
	if(rear == 20 - 1) {
		printf("Queue is full.");
		return;
	}
	
	if(front == -1 && rear == -1) {
		front = 0;
	}
	rear++;
	Q[rear] = temp;	
}

bool isempty() {
	if(front == -1 && rear == -1)
		return true;
	else
		return false;
}
