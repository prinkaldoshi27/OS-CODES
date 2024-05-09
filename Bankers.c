#include <stdio.h>
int main()
{
    // P1, P2, P3, P4, P5 are the Process names here

    int n, m, i, j, k;
    n = 5;                         // Number of processes
    m = 3;                         // Number of resources
    int alloc[5][3] = {{0, 1, 0},  // P1 // Allocation Matrix
                       {2, 0, 0},  // P2
                       {3, 0, 2},  // P3
                       {2, 1, 1},  // P4
                       {0, 0, 2}}; // P5

    int max[5][3] = {{7, 5, 3},  // P1 // MAX Matrix
                     {3, 2, 2},  // P2
                     {9, 0, 2},  // P3
                     {4, 2, 2},  // P4
                     {5, 3, 3}}; // P5

    int avail[3] = {3, 3, 2}; // Available Resources

    int f[n], ans[n], ind = 0; // initiall f[] is set to 0 for all processes /no processes has been executed yet
    for (k = 0; k < n; k++)
    {
        f[k] = 0; // initializing 0 for all processes
    }
    int need[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < n; k++) // if any process is told to wait, then it will be executed again (i.e ALL PROCESSES WILL BE CHECKED AGAIN)
    {
        for (i = 0; i < n; i++) // iterating through all processes
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind] = i;
                    ind++;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0)
        {
            flag = 0;
            printf("The following system is not safe");
            break;
        }
    }

    if (flag == 1)
    {
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++)
            printf(" P%d ->", ans[i] + 1);
        printf(" P%d", ans[n - 1] + 1);
    }

    return (0);
}
