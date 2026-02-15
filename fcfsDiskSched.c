#include <stdio.h>
#include <stdlib.h>

int main() {
    int t[20];      // track sequence
    int n;          // number of tracks to traverse
    int tohm[20];   // track differences (head movements)
    int tot = 0;
    float avhm;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the track numbers in the order of request:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);

    // Calculate head movements
    for (int i = 0; i < n - 1; i++) {
        tohm[i] = t[i + 1] - t[i];
        if (tohm[i] < 0)
            tohm[i] = -tohm[i]; // absolute difference
        tot += tohm[i];
    }

    avhm = (float)tot / (n - 1);

    // Display
    printf("\nTrack traversed\tDifference between tracks\n");
    for (int i = 0; i < n - 1; i++)
        printf("%d -> %d\t\t%d\n", t[i], t[i + 1], tohm[i]);

    printf("\nTotal head movements: %d", tot);
    printf("\nAverage head movement: %.2f\n", avhm);

    return 0;
}

