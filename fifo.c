#include <stdio.h>

#define FRAMES 3
#define PAGES 12

void display(int fr[])
{
    int i;
    printf("\n");
    for (i = 0; i < FRAMES; i++)
        printf("%d\t", fr[i]);
}

int main()
{
    int fr[FRAMES];
    int page[PAGES] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int i, j;
    int flag1, flag2;
    int pf = 0;
    int top = 0;

    // Initialize frames
    for (i = 0; i < FRAMES; i++)
        fr[i] = -1;

    // FIFO Page Replacement
    for (j = 0; j < PAGES; j++)
    {
        flag1 = 0;
        flag2 = 0;

        // Check if page already present
        for (i = 0; i < FRAMES; i++)
        {
            if (fr[i] == page[j])
            {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        // If page not present, check for empty frame
        if (flag1 == 0)
        {
            for (i = 0; i < FRAMES; i++)
            {
                if (fr[i] == -1)
                {
                    fr[i] = page[j];
                    flag2 = 1;
                    pf++;
                    break;
                }
            }
        }

        // If no empty frame, replace using FIFO
        if (flag2 == 0)
        {
            fr[top] = page[j];
            top = (top + 1) % FRAMES;
            pf++;
        }

        display(fr);
    }

    printf("\n\nNumber of page faults: %d\n", pf);

    return 0;
}

