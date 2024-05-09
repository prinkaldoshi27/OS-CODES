#include <stdio.h>

void Fifo(int noPage, int page[], int noFrame, int frame[])
{
    int i, j, framehead = 0, hit = 0, fault = 0;
    for (i = 0; i < noFrame; i++)
    {
        frame[i] = -1;
    }
    printf("Pages\tFrames\t Hit \n");
    for (i = 0; i < noPage; i++)
    {
        int count = 0;
        int res = 0;
        for (j = 0; j < noFrame; j++)
        {
            if (frame[j] != page[i])
            {
                count++;
            }
            else
            {
                hit++;
                res = 1;
                break;
            }
        }
        if (i < noFrame)
        {
            frame[fault] = page[i];
            fault++;
        }
        else if (count == noFrame)
        {
            frame[framehead] = page[i];
            fault++;
            framehead = (framehead + 1) % noFrame;
        }

        // Inside the loop
        printf("%d \t", page[i]);
        for (j = 0; j < noFrame; j++)
        {
            printf("%d ", frame[j]);
        }
        printf("\t %d\n", res);
    }
    printf("Page Faults : %d \n", fault);
    printf("Hits : %d \n", hit);
}

void LRU(int noPage, int page[], int noFrame, int frame[])
{
    int i, j, timestamp[noFrame], hit = 0, fault = 0, res = 0;
    for (i = 0; i < noFrame; i++)
    {
        frame[i] = -1;
        timestamp[i] = -1;
    }
    printf("Pages\tFrames\t Hit \n");
    for (i = 0; i < noPage; i++)
    {
        int count = 0;
        for (j = 0; j < noFrame; j++)
        {
            if (frame[j] != page[i])
            {
                count++;
            }
            else
            {
                hit++;
                res = 1;
                timestamp[j] = i;
            }
        }
        if (i < noFrame && count == noFrame)
        {
            frame[fault] = page[i];
            fault++;
            timestamp[fault] = i;
        }
        else if (count == noFrame)
        {
            fault++;
            int min = 99, minEle;
            for (j = 0; j < noFrame; j++)
            {
                if (timestamp[j] < min)
                {
                    min = timestamp[j];
                    minEle = j;
                }
            }
            frame[minEle] = page[i];
            timestamp[minEle] = i;
        }
        printf("%d \t", page[i]);
        for (j = 0; j < noFrame; j++)
        {
            printf("%d ", frame[j]);
        }
        printf("\t %d\n", res);
    }
    printf("Page Faults : %d \n", fault);
    printf("Hits : %d \n", hit);
}

int main()
{
    int noPages, ch;
    printf("Enter number of pages : ");
    scanf("%d", &noPages);
    int pages[noPages];
    printf("Enter the sequence : ");
    for (int i = 0; i < noPages; i++)
    {
        scanf("%d", &pages[i]);
    }
    int noFrames;
    printf("Enter number of frames : ");
    scanf("%d", &noFrames);
    int frames[noFrames];
    do
    {
        printf(" -- MENU -- \n 1. FIFO \n4 2. LRU \n 3. Optiomal \n 4. Exit \n Enter your choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            Fifo(noPages, pages, noFrames, frames);
            break;
        case 2:
            LRU(noPages, pages, noFrames, frames);
            break;
        case 3:
            /// Optimal(noPages, pages, noFrames, frames);
            break;
        default:
            printf("Invalid choice");
        }
    } while (ch != 4);
    return 0;
}