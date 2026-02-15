#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t[50], atr[50];
    int h, n, tot, i, j, temp;
    int sum = 0, p = 0;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the total number of tracks on disk: ");
    scanf("%d", &tot);

    printf("Enter the position of head: ");
    scanf("%d", &h);

    /* Add 0, head and last track */
    t[0] = 0;
    t[1] = h;
    t[2] = tot - 1;

    printf("Enter the track requests:\n");
    for(i = 3; i < n + 3; i++)
        scanf("%d", &t[i]);

    n = n + 3;   // total elements including 0, head and last track

    /* Sort the tracks */
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

    /* Find index of head */
    for(i = 0; i < n; i++)
        if(t[i] == h)
            break;

    /* Move towards higher end (C-SCAN direction) */
    for(j = i; j < n; j++)
        atr[p++] = t[j];

    /* Jump to beginning (circular move) */
    for(j = 0; j < i; j++)
        atr[p++] = t[j];

    /* Calculate total head movement */
    for(i = 0; i < p - 1; i++)
        sum += abs(atr[i] - atr[i + 1]);

    printf("\nTotal head movements: %d", sum);
    printf("\nAverage head movement: %.2f", (float)sum / (n - 3));

    return 0;
}

