#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("fork failed");
        return 1;
    } else if (pid == 0) {
        for (int i = 1; i <= 10; i++) {
            if (i % 2 != 0) {
                printf("Child: %d\n", i);
            }
        }
    } else {
        wait(NULL);

        for (int i = 1; i <= 10; i++) {
            if (i % 2 == 0) {
                printf("Parent: %d\n", i);
            }
        }
    }

    return 0;
}