#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIR 10
#define MAX_FILE 10

struct directory
{
    char dname[20];
    char fname[MAX_FILE][20];
    int fcnt;
} dir[MAX_DIR];

int main()
{
    int dcnt = 0, i, k, ch;
    char d[20], f[20];

    while (1)
    {
        printf("\n\n1. Create Directory");
        printf("\n2. Create File");
        printf("\n3. Delete File");
        printf("\n4. Search File");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice -- ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (dcnt < MAX_DIR)
            {
                printf("\nEnter name of directory -- ");
                scanf("%s", dir[dcnt].dname);
                dir[dcnt].fcnt = 0;
                dcnt++;
                printf("Directory created");
            }
            else
                printf("\nMaximum directories reached!");
            break;

        case 2:
            printf("\nEnter name of the directory -- ");
            scanf("%s", d);
            for (i = 0; i < dcnt; i++)
            {
                if (strcmp(d, dir[i].dname) == 0)
                {
                    if (dir[i].fcnt < MAX_FILE)
                    {
                        printf("Enter name of the file -- ");
                        scanf("%s", dir[i].fname[dir[i].fcnt]);
                        dir[i].fcnt++;
                        printf("File created");
                    }
                    else
                        printf("\nMaximum files in this directory reached!");
                    break;
                }
            }
            if (i == dcnt)
                printf("Directory %s not found", d);
            break;

        case 3:
            printf("\nEnter name of the directory -- ");
            scanf("%s", d);
            for (i = 0; i < dcnt; i++)
            {
                if (strcmp(d, dir[i].dname) == 0)
                {
                    printf("Enter name of the file -- ");
                    scanf("%s", f);
                    for (k = 0; k < dir[i].fcnt; k++)
                    {
                        if (strcmp(f, dir[i].fname[k]) == 0)
                        {
                            strcpy(dir[i].fname[k], dir[i].fname[dir[i].fcnt - 1]);
                            dir[i].fcnt--;
                            printf("File %s deleted", f);
                            break;
                        }
                    }
                    if (k == dir[i].fcnt)
                        printf("File %s not found", f);
                    break;
                }
            }
            if (i == dcnt)
                printf("Directory %s not found", d);
            break;

        case 4:
            printf("\nEnter name of the directory -- ");
            scanf("%s", d);
            for (i = 0; i < dcnt; i++)
            {
                if (strcmp(d, dir[i].dname) == 0)
                {
                    printf("Enter name of the file -- ");
                    scanf("%s", f);
                    for (k = 0; k < dir[i].fcnt; k++)
                    {
                        if (strcmp(f, dir[i].fname[k]) == 0)
                        {
                            printf("File %s found", f);
                            break;
                        }
                    }
                    if (k == dir[i].fcnt)
                        printf("File %s not found", f);
                    break;
                }
            }
            if (i == dcnt)
                printf("Directory %s not found", d);
            break;

        case 5:
            if (dcnt == 0)
                printf("\nNo directories");
            else
            {
                printf("\nDirectory\tFiles\n");
                for (i = 0; i < dcnt; i++)
                {
                    printf("%s\t", dir[i].dname);
                    for (k = 0; k < dir[i].fcnt; k++)
                        printf("%s\t", dir[i].fname[k]);
                    printf("\n");
                }
            }
            break;

        case 6:
            exit(0);

        default:
            printf("\nInvalid choice!");
        }
    }

    return 0;
}

