#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f[50] = {0};  // disk blocks: 0 = free, 1 = allocated
    int inde[50];     // blocks for each file
    int i, k, j, n, c, p;

    do
    {
        printf("\nEnter index block: ");
        scanf("%d", &p);

        if (p < 0 || p >= 50)
        {
            printf("Invalid block number! Max 0-49.\n");
            continue;
        }

        if (f[p] == 1)
        {
            printf("Block already allocated!\n");
            continue;
        }

        f[p] = 1;  // mark index block as allocated

        printf("Enter number of data blocks: ");
        scanf("%d", &n);

        if (n <= 0 || n > 50)
        {
            printf("Invalid number of blocks!\n");
            f[p] = 0;
            continue;
        }

        printf("Enter the data blocks:\n");
        int valid = 1;

        for (i = 0; i < n; i++)
        {
            scanf("%d", &inde[i]);
            if (inde[i] < 0 || inde[i] >= 50)
            {
                printf("Invalid block number %d!\n", inde[i]);
                valid = 0;
                break;
            }
            if (f[inde[i]] == 1)
            {
                printf("Block %d already allocated!\n", inde[i]);
                valid = 0;
                break;
            }
        }

        if (!valid)
        {
            f[p] = 0; // free index block
            continue;
        }

        // allocate data blocks
        for (j = 0; j < n; j++)
            f[inde[j]] = 1;

        printf("\nFile allocated successfully.\n");
        printf("Index block %d points to data blocks:\n", p);
        for (k = 0; k < n; k++)
            printf("%d -> %d : %d\n", p, inde[k], f[inde[k]]);

        printf("\nDo you want to enter more files? (1-Yes / 0-No): ");
        scanf("%d", &c);

    } while (c == 1);

    return 0;
}

