/* Program to simulate Optimal Page Replacement */

#include <stdio.h>

#define MAX 50

int fr[MAX], n, m;

void display()
{
    int i;
    for (i = 0; i < m; i++)
        printf("%d\t", fr[i]);
    printf("\n");
}

int main()
{
    int i, j, page[MAX], lg[MAX];
    int max, index, k;
    int flag1, flag2, pf = 0, found;
    float pr;

    printf("Enter length of the reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &page[i]);

    printf("Enter number of frames: ");
    scanf("%d", &m);

    // Initialize frames
    for (i = 0; i < m; i++)
        fr[i] = -1;

    // Optimal Page Replacement
    for (j = 0; j < n; j++)
    {
        flag1 = flag2 = 0;

        // Check if page already present
        for (i = 0; i < m; i++)
        {
            if (fr[i] == page[j])
            {
                flag1 = flag2 = 1;
                break;
            }
        }

        // If empty frame available
        if (flag1 == 0)
        {
            for (i = 0; i < m; i++)
            {
                if (fr[i] == -1)
                {
                    fr[i] = page[j];
                    pf++;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If replacement needed
        if (flag2 == 0)
        {
            for (i = 0; i < m; i++)
            {
                lg[i] = -1;

                for (k = j + 1; k < n; k++)
                {
                    if (fr[i] == page[k])
                    {
                        lg[i] = k;
                        break;
                    }
                }
            }

            // Find page used farthest in future
            index = 0;
            max = lg[0];

            for (i = 1; i < m; i++)
            {
                if (lg[i] == -1)   // Not used again
                {
                    index = i;
                    break;
                }
                if (lg[i] > max)
                {
                    max = lg[i];
                    index = i;
                }
            }

            fr[index] = page[j];
            pf++;
        }

        display();
    }

    printf("\nNumber of page faults: %d\n", pf);

    pr = (float)pf / n * 100;
    printf("Page fault rate = %.2f%%\n", pr);

    return 0;
}

