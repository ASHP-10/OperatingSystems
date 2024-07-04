#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
    0 - has not been allocated
    1 - allocated
    2 - cannot be allocated
*/

struct memoryBlock {
    char process[5];
    int size;
    int allocated;
    struct memoryBlock *link;
} b[10], *temp1 = NULL, *temp2 = NULL, *head = NULL, *new;

struct process{
    char name[5];
    int size;
    int allocated;
} p[10];

int main() {

    int n,m,choice1,Fit;
    int mno = 0;

    //inputting datas
    printf("Enter the number of memory blocks:");
    scanf("%d",&m);

    printf("Enter the type of memory block:\n1. Fixed\n2. Variable\n");
    scanf("%d",&choice1);

    if(choice1 == 1) {                  //fixed-choice1(1)
        for(int i = 0; i < m; i++) {
            printf("Enter the size of the block %d in KB: ",i);
            scanf("%d", &b[i].size);

            b[i].allocated = 0;
            strcpy(b[i].process,"FREE");
        }
    } /*else if(choice1 == 2) {           //variable-choice1(2)
        for(int i = 0; i < m; i++) {
            temp1 = (struct memoryBlock *)malloc(sizeof(struct memoryBlock));
            if(temp1 == NULL) {
                printf("Memory allocation failed");
                exit(-1);
            }
            int size, i = 0;

            printf("Enter the size of the block %c in KB: ",i++);
            scanf("%d", &size);

            temp1 = head;

            if(head == NULL) {
                head = temp1;
            } else {
                while(temp1 -> link != NULL) {
                    temp1 = temp1 -> link;
                }
            }

            temp1 -> size = size;
            temp1 -> allocated = 0;
            strcpy(temp1 -> process,"FREE");
        }
    } */

    printf("Enter the number of processes:");
    scanf("%d",&n);

    for(int i = 0; i < n; i++) {
        printf("Enter the name of the process: ");
        scanf("%s", p[i].name);

        printf("Enter the size of the process %s in KB: ",p[i].name);
        scanf("%d", &p[i].size);

        p[i].allocated = 0;
    }

    printf("Enter the type of Allocation method to be used:\n1. First Fit\n2. Best Fit\n3. Worst Fit");
    scanf("%d",&Fit);


    int pno = 0;
    int memdex = 0;
    if(Fit == 1) {  //first fit
        if(choice1 == 2)
            temp1 = head;

        while(pno < n) {
            if(choice1 == 1) {
                for(int i = 0; i < m; i++) {
                    if(b[i].size >= p[pno].size && b[i].allocated == 0 && p[pno].allocated != 1) {
                        strcpy(b[i].process, p[pno].name);
                        p[pno].allocated = 1;
                        b[i].allocated = 1;
                        break;
                    }
                    p[pno].allocated = 2;
                }
            } /* else if(choice1 == 2) {
                while(pno < n) {
                    temp1 = head;
                    do{
                       if(temp1 -> size >= p[pno].size && temp1 -> allocated == 0 && p[pno].allocated != 1) {
                            strcpy(temp1 -> process, p[pno].name);
                            p[pno].allocated = 1;
                            temp1 -> allocated = 1;
                            
                            //creating new block
                            new = (struct memoryBlock *)malloc(sizeof(struct memoryBlock));
                            if(new == NULL) {
                                printf("Memory allocation failed");
                                exit(-1);
                            }

                            new -> size = temp1 -> size - p[pno].size;
                            new -> allocated = 0;
                            strcpy(new -> process,"FREE");
                            
                            if(temp1 -> link != NULL) {
                                temp2 = temp1 -> link;
                            }

                            temp1 -> link = new;
                            temp1 -> size = p[pno].size;

                            if(temp1 -> link == NULL) {
                                new -> link = NULL;
                            } else {
                                new -> link = temp2;
                            }
                        }
                    }while(temp1 -> link != NULL);
                }
            } */
            pno++;
        }
    } else if (Fit == 2) {  //Best fit
        while(pno < n) {
            int minSize = 1024;
            int minIndex = -1;

            for(int i = 0; i < m; i++) {
                if(b[i].size >= p[pno].size && b[i].allocated != 1 && p[pno].allocated != 1) {
                    if(minSize > b[i].size) { 
                        minSize = b[i].size;
                        minIndex = i;
                    }
                }
            }

            if(minIndex != -1) {
                strcpy(b[minIndex].process,p[pno].name);
                b[minIndex].allocated = 1;
                p[pno].allocated = 1;
            } else {
                p[pno].allocated = 2;
            }

            pno++;
        }
    } else if(Fit == 3) {  //Worst fit
        while(pno < n) {
            int maxSize = -1;
            int maxIndex = -1;

            for(int i = 0;i < m; i++) {
                if(b[i].size >= p[pno].size && b[i].allocated != 1 && b[i].allocated != 1) {
                    if(maxSize < b[i].size) {
                        maxSize = b[i].size;
                        maxIndex = i;
                    }
                }
            }
            
            if(maxIndex != -1) {
                strcpy(b[maxIndex].process,p[pno].name);
                b[maxIndex].allocated = 1;
                p[pno].allocated = 1;
            } else {
                p[pno].allocated = 2;
            }
            pno++;
        }
    }

    //memory block printing for fixed blocks
    if(choice1 == 1) {
        for(int i = 0; i < m; i++) {
            printf("________");
        } printf("\n\n");

        for(int i = 0; i < m; i++) {
            printf("|%s\t",b[i].process);
        } printf("|\n");

        for(int i = 0; i < m; i++) {
            printf("________");
        } printf("\n\n");

        for(int i = 0; i < n; i++) {
            if(p[i].allocated == 2) {
                printf("Process %s is not allocated\n", p[i].name);
            }
        }
    } /*else if(choice1 == 2) {
        //counting the number of blocks so as to be able to print the lines accordingly
        int count = 0;

        temp1 = head;
        if(head == NULL) {
            count = 1;
        } else {
            do{
                count++;
                temp1 = temp1 -> link;
            }while(temp1 -> link != NULL);
        }

        //memory block printing for dyanmic
        for(int i = 0; i < count; i++) {
            printf("________");
        } printf("\n\n");

        temp1 = head;
        for(int i = 0; i < count; i++) {
            printf("%s\t",temp1 -> process);
            temp1 = temp1 -> link;
        } printf("|\n");

        for(int i = 0; i < count; i++) {
            printf("________");
        } printf("\n\n");

        for(int i = 0; i < n; i++) {
            if(p[i].allocated == 2) {
                printf("Process %s is not allocated\n", p[i].name);
            }
        }
    }*/
    
    return 0;
}