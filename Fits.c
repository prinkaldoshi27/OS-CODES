#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int i, j;
    int allocation[n];
    for (i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %i\t\t", i + 1);
        printf("%i\t\t", processSize[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

void nextFit(int blockSize[], int m, int processSize[], int n)
{
    int i, j;
    int allocation[n];
    for (i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    int start_index = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = start_index; i < m; i++)
        {
            if (blockSize[i] >= processSize[j])
            {
                allocation[j] = i;
                blockSize[i] = 0;
                start_index = i;l
                break;
            }
            start_index = (start_index + 1) % m;
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %i\t\t", i + 1);
        printf("%i\t\t", processSize[i]);
        if (allocation[i] != -1)
            printf("%i", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n)
{

    int allocation[n];

    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++)
    {

        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1)
        {

            allocation[i] = bestIdx;

            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;
    for (int i = 0; i < n; i++)
    {
        int wstIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (wstIdx == -1)
                    wstIdx = j;
                else if (blockSize[wstIdx] < blockSize[j])
                    wstIdx = j;
            }
        }

        if (wstIdx != -1)
        {
            allocation[i] = wstIdx;
            blockSize[wstIdx] -= processSize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
}

int main()
{
    printf("\n --- First Fit ---");
    int m;
    int n;
    int blockSize[] = {100, 500, 200, 450, 600};
    int processSize[] = {212, 417, 112, 426};
    m = sizeof(blockSize) / sizeof(blockSize[0]);
    n = sizeof(processSize) / sizeof(processSize[0]);
    firstFit(blockSize, m, processSize, n);
    printf("\n--- Best Fit ---");
    int m1;
    int n1;
    int blockSize1[] = {100, 500, 200, 300, 600};
    int processSize1[] = {212, 417, 112, 426};
    m1 = sizeof(blockSize1) / sizeof(blockSize1[0]);
    n1 = sizeof(processSize1) / sizeof(processSize1[0]);
    bestFit(blockSize1, m1, processSize1, n1);
    printf("\n--- Worst Fit ---");
    int m2;
    int n2;
    int blockSize2[] = {100, 500, 200, 300, 600};
    int processSize2[] = {212, 417, 112, 426};
    m2 = sizeof(blockSize2) / sizeof(blockSize2[0]);
    n2 = sizeof(processSize2) / sizeof(processSize2[0]);
    worstFit(blockSize2, m2, processSize2, n2);
    printf("\n--- Next Fit ---");
    int m3;
    int n3;
    int blockSize3[] = {100, 500, 200, 450, 600};
    int processSize3[] = {212, 417, 112, 426};
    m3 = sizeof(blockSize3) / sizeof(blockSize3[0]);
    n3 = sizeof(processSize3) / sizeof(processSize3[0]);
    nextFit(blockSize3, m3, processSize3, n3);
    return 0;
}