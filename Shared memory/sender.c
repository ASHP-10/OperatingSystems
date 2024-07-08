#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

int main()
{
    void *shared_memory;
    char buff[100];
    int shmid = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);

    printf("%d id",shmid);

    shared_memory = shmat(shmid, NULL, 0);

    printf("Enter number: ");
    read(0, buff, 100);
    strcpy(shared_memory, buff);

    return 0;
}
