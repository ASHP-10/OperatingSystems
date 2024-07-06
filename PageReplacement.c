#include <stdio.h>
#include <stdbool.h>

int F;
int p;

int FIFO(int s[], int p);
int LRU(int s[], int p);

int main() 
{
    int choice;

    printf("Enter the number of frames: ");
    scanf("%d", &F);

    printf("Enter the number of pages: ");
    scanf("%d",&p);

    int s[p];

    printf("Enter the string: ");
    for(int i = 0; i < p; i++) 
    scanf("%d",&s[i]);

    printf("MENU\n1.FIFO\n2.LRU");
    scanf("%d",&choice);

    int pf;
    switch(choice) {
        case 1:
            pf = FIFO(s, 20);
            printf("%d",pf);
            break;
        case 2:
            pf = LRU(s, 20);
            printf("%d",pf);
            break;
    }

    return 0;
}

int FIFO(int s[], int n) {
    int pagefault = 0;

    int f[F];

    for(int i = 0; i < F; i++) 
        f[i] = -1; 

    for(int i = 0; i < n; i++) {
        bool pageFound = false;
        for(int j = 0; j < F; j++) {
            if(s[i] == f[j]) {
                pageFound = true;
                break;
            }
        }

        if(!pageFound) {
            f[pagefault % F] = s[i];
            pagefault++;
            printf("pg %d\n",i + 1);
        }
    }

    return pagefault;
}

int LRU(int s[], int n) {
    int pagefault = 0;
    int time = 1;

    int f[F];
    int access[p];

    for(int i = 0; i < F; i++) {
        f[i] = -1;
        access[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        bool pageFound = false;
        for(int j = 0; j < F; j++) {
            if(f[j] == s[i]) {
                pageFound = true;
                access[j] = i;
                break;
            }
        }

        if(!pageFound) {
            if(i < F) {
                f[i] = s[i];
                access[i] = time++;
            } else {
                int min = 0;
                for(int j = 1; j < F; j++) {
                    if(access[min] > access[j]) {
                        min = j;
                    }
                }

                f[min] = s[i];
                access[min] = time++;
            }
            pagefault++;
            printf("%d pagefault\n",i + 1);
        }

    }
    

    return pagefault;
}
