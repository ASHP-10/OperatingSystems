#include <stdio.h>

struct mem{
    int size;
    int remaining;
}m[10];

struct process{
    char pname[20];
    int size;
    int allocated;
}p[10];

int main()
{
    int nb;

    printf("Enter the number of blocks: ");
    scanf("%d",&nb);

    printf("Enter the size of blocks\n");
    for(int i = 0; i <nb; i++) {
        scanf("%d",&m[i].size);
        m[i].remaining = m[i].size;
    }

    int np;

    printf("Enter the number of processes: ");
    scanf("%d",&np);

    for(int i = 0; i < np; i++) {
        printf("Name of process %d: ", i + 1);
        scanf("%s",p[i].pname);
        printf("Size of proces %d: ", i + 1);
        scanf("%d",&p[i].size);
        p[i].allocated = -1;
    }

    // //first fit
    // for(int i = 0; i < np; i++) {
    //     for(int j = 0; j < nb; j++) {
    //         if(p[i].size <= m[j].remaining) {
    //             m[j].remaining -= p[i].size;
    //             p[i].allocated = j + 1;
    //             break;
    //         }
    //     }
    // }

    // // best fit
    // for(int i = 0; i < np; i++) {
    //     int min = __INT_MAX__;
    //     int index = -1;
    //     for(int j = 0; j < nb; j++) {
    //         int bs = m[j].remaining - p[i].size;
    //         if(bs < min && bs >= 0) {
    //             min = bs;
    //             index = j;
    //         }
    //     }
    //     if(index != -1) {
    //         m[index].remaining -= p[i].size;
    //         p[i].allocated = index + 1;
    //     }
    // }


    //worst fit
    for(int i = 0; i < np; i++) {
        int max = 0;
        int index = -1;
        for(int j = 0; j < nb; j++) {
            int bs = m[j].remaining - p[i].size;
            if(bs > max && bs >=0 && bs >= 0) {
                max = bs;
                index = j;
            }
        }
        if(index != -1) {
            m[index].remaining -= p[i].size;
            p[i].allocated = index + 1;
        }
    }

    for(int i = 0; i < np; i++) {
        if(p[i].allocated == -1) 
            printf("%s is not allocated\n",p[i].pname);
        else
            printf("%s is allocated in %d block\n", p[i].pname, p[i].allocated);
    }

    return 0;
}