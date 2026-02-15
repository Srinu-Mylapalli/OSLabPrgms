#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f[50], i, st, len, j, choice;

    // Initialize all blocks as free
    for (i = 0; i < 50; i++)
        f[i] = 0;

    do
    {
        printf("\nEnter the starting block & length of file: ");
        scanf("%d %d", &st, &len);

        if (st < 0 || st + len > 50)
        {
            printf("Invalid block range! Maximum blocks = 50.\n");
            continue;
        }

        // Check and allocate blocks
        int allocated = 1;
        for (j = st; j < st + len; j++)
        {
            if (f[j] == 0)
            {
                f[j] = 1; // mark as allocated
                printf("%d->%d\n", j, f[j]);
            }
            else
            {
                printf("Block %d already allocated. File allocation failed!\n", j);
                allocated = 0;
                break;
            }
        }

        if (allocated)
            printf("File allocated to disk.\n");

        printf("Do you want to enter more files? (1-Yes / 0-No): ");
        scanf("%d", &choice);

    } while (choice == 1);

    return 0;
}

