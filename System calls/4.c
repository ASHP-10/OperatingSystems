#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    char *filename = "index.html";
    struct stat fileStat;

    printf("%o",fileStat.st_mode);

    printf("File Size: %ld bytes\n", fileStat.st_size);

    printf("Last Access Time: %s", ctime(&fileStat.st_atime));

    printf("Last Modification Time: %s", ctime(&fileStat.st_mtime));

    return 0;
}