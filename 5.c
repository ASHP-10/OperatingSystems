#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;
    char * filename = "index.html";

    if(S_ISDIR(fileStat.st_mode)) {
        printf("%s is a directory.\n", filename);
    } else if(S_ISREG(fileStat.st_mode)) {
        printf("%s is a regular file.\n", filename);
    } else {
        printf("%s is not a regular file or directory.\n", filename);
    }

    return 0;
}