#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct directory
{
    char dname[20];
    char fname[10][20];
    int fcnt;
} dir;

int main()
{
    int i, ch;
    char f[20];

    dir.fcnt = 0;

    printf("\nEnter name of directory -- ");
    scanf("%s", dir.dname);

    while (1)
    {
        printf("\n\n1. Create File");
        printf("\n2. Delete File");
        printf("\n3. Search File");
        printf("\n4. Display Files");
        printf("\n5. Exit");
        printf("\nEnter your choice -- ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (dir.fcnt < 10)
            {
                printf("\nEnter the name of the file -- ");
                scanf("%s", dir.fname[dir.fcnt]);
                dir.fcnt++;
            }
            else
            {
                printf("\nDirectory Full!");
            }
            break;

        case 2:
            printf("\nEnter the name of the file -- ");
            scanf("%s", f);

            for (i = 0; i < dir.fcnt; i++)
            {
                if (strcmp(f, dir.fname[i]) == 0)
                {
                    printf("File %s is deleted", f);
                    strcpy(dir.fname[i], dir.fname[dir.fcnt - 1]);
                    dir.fcnt--;
                    break;
                }
            }

            if (i == dir.fcnt)
                printf("File %s not found", f);
            break;

        case 3:
            printf("\nEnter the name of the file -- ");
            scanf("%s", f);

            for (i = 0; i < dir.fcnt; i++)
            {
                if (strcmp(f, dir.fname[i]) == 0)
                {
                    printf("File %s is found", f);
                    break;
                }
            }

            if (i == dir.fcnt)
                printf("File %s not found", f);
            break;

        case 4:
            if (dir.fcnt == 0)
            {
                printf("\nDirectory Empty");
            }
            else
            {
                printf("\nFiles in directory %s are:\n", dir.dname);
                for (i = 0; i < dir.fcnt; i++)
                    printf("%s\n", dir.fname[i]);
            }
            break;

        case 5:
            exit(0);

        default:
            printf("\nInvalid choice!");
        }
    }

    return 0;
}

