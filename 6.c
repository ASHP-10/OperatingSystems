#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    DIR *d;
    struct dirent *dir;
    struct stat fileStat;
    char *dirName = ".";

    d = opendir(dirName);
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            stat(dir->d_name, &fileStat);

            printf("Name: %s, Type: ", dir->d_name);
            if(S_ISDIR(fileStat.st_mode)) {
                printf("Directory\n");
            } else if(S_ISREG(fileStat.st_mode)) {
                printf("Regular File\n");
            } else {
                printf("Other\n");
            }
        }
        closedir(d);
    } else {
        perror("Unable to open directory");
        return 1;
    }

    return 0;
}