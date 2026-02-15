#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f[50] = {0};  // disk blocks: 0 = free, 1 = allocated
    int p, a, st, len, j, c;

    // Mark already allocated blocks
    printf("Enter how many blocks are already allocated: ");
    scanf("%d", &p);
    if (p > 50)
    {
        printf("Maximum 50 blocks allowed!\n");
        return 0;
    }

    printf("Enter the block numbers that are already allocated: ");
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &a);
        if (a < 0 || a >= 50)
        {
            printf("Invalid block number %d!\n", a);
            i--;
            continue;
        }
        f[a] = 1;
    }

    do
    {
        printf("\nEnter the starting block & length of file: ");
        scanf("%d %d", &st, &len);

        if (st < 0 || st + len > 50)
        {
            printf("Invalid block range! Maximum blocks = 50.\n");
            continue;
        }

        int canAllocate = 1;

        // Check if all blocks in the range are free
        for (j = st; j < st + len; j++)
        {
            if (f[j] == 1)
            {
                printf("Block %d is already allocated. File cannot be allocated.\n", j);
                canAllocate = 0;
                break;
            }
        }

        // Allocate if all blocks are free
        if (canAllocate)
        {
            for (j = st; j < st + len; j++)
            {
                f[j] = 1;
                printf("%d -> Allocated\n", j);
            }
            printf("File allocated successfully.\n");
        }

        printf("Do you want to enter one more file? (Yes-1 / No-0): ");
        scanf("%d", &c);

    } while (c == 1);

    return 0;
}

