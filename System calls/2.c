#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("fork failed");
        return -1;
    } else if (pid == 0) {
        
        printf("Child: My PID is %d, my parent's PID is %d\n", getpid(), getppid());
    } else {
        
        printf("Parent: My PID is %d, my child's PID is %d\n", getpid(), pid);
    }

    
    return 0;
}