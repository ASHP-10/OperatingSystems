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
    int start, end;

    printf("Enter disk number from start to end:\n");
    scanf("%d%d",&start, &end);

    printf("Enter the disk positions:\n");
    for(int i = 0; i < n; i++) 
        scanf("%d", &d[i]);

    int total = 0;

    int dir;

    printf("1 for right and 2 for left: ");
    scanf("%d",&dir);

    int right[10];
    int left[10];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(d[j] > d[j + 1]) {
                int temp = d[j + 1];
                d[j + 1] = d[j];
                d[j] = temp;
            }
        }
    }

    int li = 0;
    int ri = 0;

    for(int i = 0; i < n; i++) {
        if(d[i] < current) 
            left[li++] = d[i];
        else
            right[ri++] = d[i];
    }

    
    if(dir == 1) {
        for(int j = 0; j < ri; j++) {
        total += abs(current - right[j]);
        current = right[j];
        }
        if (ri > 0) {
            total += abs(current - end);
            current = end;
        }
        for(int j = li - 1; j >= 0; j--) {
            total += abs(current - left[j]);
            current = left[j];
        }
    } else {
        if(dir != 2) 
            printf("Invalid direction, going left automaitcally");

        for(int j = li - 1; j >= 0; j--) {
        total += abs(current - left[j]);
        current = left[j];
        }
        if (li > 0) {
            total += abs(current - start);
            current = start;
        }
        for(int j = 0; j < ri; j++) {
            total += abs(current - right[j]);
            current = right[j];
        }
    }
    
    printf("%d",total);

    return 0;
}