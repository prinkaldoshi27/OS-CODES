#include <stdio.h>

int s = 0; // semaphore //1=LOCK //0=UNLOCK
int e = 4; // size of the buffer //EMPTY
int n = 0; // counter //FULL
int b[4];  // array of buffer with size 4

int wait(int *s)
{
    (*s)--;
    return *s;
}

int signal(int *s)
{
    (*s)++;
    return *s;
}

void producer()
{
    int a;
    printf("Enter value to produce : ");
    scanf("%d", &a);

    wait(&e); // decrement empty
    wait(&s); // decrement semaphore

    b[n] = a;

    signal(&n);
    signal(&s);

    printf("Buffer : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}
void consumer()
{
    wait(&s);
    for (int i = 1; i < n; i++)
    {
        b[i - 1] = b[i]; // shift the buffer
    }
    wait(&n);
    signal(&s);
    signal(&e);

    printf("Buffer : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
}
int main()
{
    int ch;
    do
    {
        printf("\n1: Produce\n2: Consume\n3: Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            if (e == 0)
            {
                printf("\nBuffer is full\n");
            }
            else
            {
                producer();
            }
            break;
        case 2:
            if (e == 4)
            {
                printf("\nBuffer is empty\n");
            }
            else
            {
                consumer();
            }
            break;
        case 3:
            printf("\nExiting...\n");
            break;
        default:
            printf("Enter a valid choice\n");
        }
    } while (ch != 3);

    return 0;
}