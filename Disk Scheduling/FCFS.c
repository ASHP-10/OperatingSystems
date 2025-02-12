#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int current;
    int n;

    printf("Enter the current head position: ");
    scanf("%d", &current);

    printf("Enter the number of disk positions: ");
    scanf("%d",&n);

    int d[n];

    printf("Enter the disk positions:\n");
    for(int i = 0; i < n; i++) 
        scanf("%d", &d[i]);

    int total = 0;

    for(int i = 0; i < n; i++) {
        total += abs(current - d[i]);
        current = d[i];
        printf("%d\n", total);
    }

    printf("%d",total);

    return 0;
}