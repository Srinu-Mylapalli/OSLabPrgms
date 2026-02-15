#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    int alloc[10][10], max[10][10], need[10][10];
    int total[10], work[10];
    char finish[10];
    int i, j, k, count = 0;

    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
        finish[i] = 'n';

    printf("Enter the claim (maximum) matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter total resources available:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &total[i]);

    // Calculate available resources
    for (i = 0; i < m; i++)
    {
        int sum = 0;
        for (j = 0; j < n; j++)
            sum += alloc[j][i];
        work[i] = total[i] - sum;
    }

    // Calculate need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printf("\nSafe sequence check:\n");
    int safe = 1;

    while (count < n)
    {
        int allocated = 0; // flag to check if any process could proceed in this pass

        for (i = 0; i < n; i++)
        {
            if (finish[i] == 'n')
            {
                int canAllocate = 1;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canAllocate = 0;
                        break;
                    }
                }

                if (canAllocate)
                {
                    printf("Process %d can be allocated resources.\n", i + 1);

                    for (k = 0; k < m; k++)
                        work[k] += alloc[i][k];

                    printf("Available resources now: ");
                    for (k = 0; k < m; k++)
                        printf("%d ", work[k]);
                    printf("\n");

                    finish[i] = 'y';
                    count++;
                    allocated = 1;
                }
            }
        }

        if (!allocated) // No process could proceed → unsafe
        {
            safe = 0;
            break;
        }
    }

    if (safe)
        printf("\nSystem is in a SAFE state.\n");
    else
        printf("\nSystem is NOT safe! Deadlock may occur.\n");

    return 0;
}

