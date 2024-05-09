#include <stdio.h>

int absolute(int x, int y)
{
    if (x >= y)
    {
        return x - y;
    }
    else
    {
        return y - x;
    }
}

int FCFS(int n, int p, int m[], int ans[])
// m = order []
// p = head
// n = number of movements
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            total += absolute(p, m[i]);
        }
        else
        {
            total += absolute(m[i - 1], m[i]);
        }
        ans[i] = m[i];
    }

    return total;
}

int SSTF(int n, int p, int m[], int ans[])
{
    int total = 0;
    int current, v[n];
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            current = p;
        }
        else
        {
            current = ans[i - 1];
        }
        int min = 199, j, x;
        for (j = 0; j < n; j++)
        {
            if (absolute(current, m[j]) <= min && v[j] == 0)
            {
                min = absolute(current, m[j]);
                x = j;
            }
        }
        v[x] = 1;
        total += min;
        ans[i] = m[x];
    }

    return total;
}

void print(int n, int p, int ans[], int total)
{
    printf("\nTrack movements are as follows : \n");
    printf("%d -> %d", p, ans[0]);
    for (int i = 1; i < n; i++)
    {
        printf(" -> %d", ans[i]);
    }

    printf("\nTotal seek time is : %d\n", total);
}

int main()
{

    int n, p;
    printf("\nEnter the number of movements : ");
    scanf("%d", &n);

    int m[n];
    printf("\nEnter %d movements (0 - 199) : ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m[i]);
    }

    printf("\nEnter the current head location : ");
    scanf("%d", &p);
    // int n=5,p=65;
    // int m[]={25,51,60,132,189};
    // int m[]={25,51,60,132,189};
    int total, ans[n];
    int c;
    do
    {
        printf("\n1  -->  FCFS\n2  -->  SSTF\n3  -->  SCAN\n4  -->  CSCAN\n5  -->  LOOK\n6  -->  CLOOK\n7  -->  EXIT\n");
        printf("\nEnter your choice : ");
        scanf("%d", &c);
        int u;
        switch (c)
        {
        case 1:
            total = FCFS(n, p, m, ans);
            print(n, p, ans, total);
            break;
        case 2:
            total = SSTF(n, p, m, ans);
            print(n, p, ans, total);
            break;
        // case 3:
        //     u = 1;
        //     total = SCAN(n, p, m, ans, u);
        //     print(n + 1, p, ans, total);
        //     break;
        // case 4:
        //     u = 0;
        //     total = CSCAN(n, p, m, ans, u);
        //     print(n + 2, p, ans, total);
        //     break;
        // case 5:
        //     u = 1;
        //     total = LOOK(n, p, m, ans, u);
        //     print(n, p, ans, total);
        //     break;
        // case 6:
        //     u = 1;
        //     total = CLOOK(n, p, m, ans, u);
        //     print(n, p, ans, total);
        //     break;
        case 7:
            printf("\nExiting...\n");
            break;
        default:
            printf("Enter a valid choice\n");
        }
    } while (c != 7);

    return 0;
}