#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t[20], h, n, i, j, temp;
    int total = 0;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the position of head: ");
    scanf("%d", &h);

    printf("Enter the tracks:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &t[i]);

    // Add head position into track list
    t[n] = h;
    n++;

    // Sort the tracks
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(t[j] > t[j + 1])
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find index of head
    for(i = 0; i < n; i++)
        if(t[i] == h)
            break;

    // Move left first
    for(j = i; j > 0; j--)
        total += abs(t[j] - t[j - 1]);

    // Then move right
    for(j = i; j < n - 1; j++)
        total += abs(t[j] - t[j + 1]);

    printf("\nTotal head movement: %d", total);
    printf("\nAverage head movement: %.2f", (float)total / (n - 1));

    return 0;
}

