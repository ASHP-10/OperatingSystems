#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        printf("fork failed");
        return 1;
    } else if (pid == 0) {
        char *args[] = {"cat", argv[1], NULL};
        execvp("cat", args);

        printf("execvp failed");
        exit(1);
    } else {
        wait(NULL);
        printf("Parent: Child process has terminated.\n");
    }

    return 0;
}

}}}}}
}
}
{}}; ,/

}
;
;
;
;

;
;
}
;dafd;
;fsdaf
;
;
innt;
;__intptr_t;
labs;
;
;
;
;
;
;
;
;
;
;s
d;
s;d 
a