#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int lengthOfLastWord(const char *s)
{
    int curWordLength = 0;
    int i = strlen(s) - 1;

    while (i >= 0)
    {
        int space = s[i] == ' ';

        if (space && curWordLength > 0)
        {
            break;
        }
        else if (!space)
        {
            curWordLength++;
        }

        i--;
    }

    return curWordLength;
}

char *join(int nstrs, char *strs[])
{
    int maxSize = 0;

    for (int i = 0; i < nstrs; i++)
    {
        maxSize += strlen(strs[i]) + 1;
    }

    char *result = (char *)malloc(maxSize * sizeof(char));
    if (result == NULL)
    {
        fprintf(stderr, "Error: Failed to allocate memory joining string\n");
        return NULL;
    }

    for (int i = 0; i < nstrs; i++)
    {
        // what the fuck, will this segfault?
        if (strlen(result) == 0)
        {
            sprintf(result, "%s", strs[i]);
        }
        else
        {
            sprintf(result, "%s %s", result, strs[i]);
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        fprintf(stderr, "Missing required argument str\nUsage: %s [str]\n", argv[0]);
        return 1;
    }

    char *joined = join(argc - 1, &argv[1]);

    if (joined == NULL)
    {
        fprintf(stderr, "Failed to join arguments");
        return 1;
    }

    printf("Length of last word \"%s\" = %d\n", joined, lengthOfLastWord(joined));

    free(joined);
    return 0;
}
