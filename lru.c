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
    int p[PAGES] = {2,3,2,1,5,2,4,5,3,2,5,2};
    int fs[FRAMES];
    int i, j, k, index;
    int flag1, flag2;
    int pf = 0;

    // Initialize frames
    for (i = 0; i < FRAMES; i++)
        fr[i] = -1;

    // LRU Algorithm
    for (j = 0; j < PAGES; j++)
    {
        flag1 = flag2 = 0;

        // Check if page already present
        for (i = 0; i < FRAMES; i++)
        {
            if (fr[i] == p[j])
            {
                flag1 = flag2 = 1;
                break;
            }
        }

        // If empty frame available
        if (flag1 == 0)
        {
            for (i = 0; i < FRAMES; i++)
            {
                if (fr[i] == -1)
                {
                    fr[i] = p[j];
                    pf++;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If replacement needed
        if (flag2 == 0)
        {
            for (i = 0; i < FRAMES; i++)
                fs[i] = 0;

            // Check backward for LRU
            for (k = j - 1; k >= 0; k--)
            {
                for (i = 0; i < FRAMES; i++)
                {
                    if (fr[i] == p[k] && fs[i] == 0)
                        fs[i] = 1;
                }
            }

            // Find least recently used
            for (i = 0; i < FRAMES; i++)
            {
                if (fs[i] == 0)
                {
                    index = i;
                    break;
                }
            }

            fr[index] = p[j];
            pf++;
        }

        display(fr);
    }

    printf("\n\nNumber of page faults: %d\n", pf);

    return 0;
}

