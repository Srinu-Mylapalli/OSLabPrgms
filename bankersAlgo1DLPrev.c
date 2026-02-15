#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m; // n = processes, m = resources
    int alloc[10][10], max[10][10], need[10][10];
    int total[10], avail[10], work[10];
    char finish[10];
    int i, j, k;

    printf("Enter number of processes and resources: ");
    scanf("%d %d", &n, &m);

    // Input max claim matrix
    printf("Enter maximum resources required for each process (claim matrix):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    // Input allocation matrix
    printf("Enter resources currently allocated to each process (allocation matrix):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    // Input total resources
    printf("Enter total resources in the system:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &total[i]);

    // Calculate available resources
    for (i = 0; i < m; i++) {
        int sum = 0;
        for (j = 0; j < n; j++)
            sum += alloc[j][i];
        avail[i] = total[i] - sum;
        work[i] = avail[i];
    }

    // Calculate need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Initialize finish flags
    for (i = 0; i < n; i++)
        finish[i] = 0;

    printf("\nDeadlock Prevention Check:\n");

    int safeCount = 0;
    int progress;

    do {
        progress = 0;
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                int canAllocate = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = 0;
                        break;
                    }
                }
                if (canAllocate) {
                    printf("Process P%d can safely execute.\n", i + 1);
                    // Release resources after execution
                    for (k = 0; k < m; k++)
                        work[k] += alloc[i][k];
                    finish[i] = 1;
                    safeCount++;
                    progress = 1;
                }
            }
        }
        if (!progress)
            break; // No process can proceed
    } while (safeCount < n);

    if (safeCount == n) {
        printf("\nSystem is in a SAFE STATE. No deadlock will occur.\n");
    } else {
        printf("\nSystem is NOT SAFE. Deadlock may occur!\n");
    }

    return 0;
}

