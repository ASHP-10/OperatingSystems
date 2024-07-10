#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed");
        return -1;
    } else if (pid == 0) {
        printf("I am child\n");
    } else {
        printf("I am parent\n");
    }

    return 0;
}