#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>

int main()
{
    void *shared_memory;
    char buff[100];
    int shmid = shmget((key_t)1234, 1024, 0666);

    printf("%d id",shmid);

    shared_memory = shmat(shmid, NULL, 0);

    printf("%s",(char *)shared_memory);


    return 0;
}