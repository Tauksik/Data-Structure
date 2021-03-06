#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1;

int main()
{
    int ch;
    int item, MAX, i;
    printf("Enter the size of queue: ");
    scanf("%d", &MAX);
    int queue[MAX];
    do
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (front == (rear + 1) % MAX)
                printf("Queue is full\n");
            else
            {
                printf("Enter the element: ");
                scanf("%d", &item);
                rear = (rear + 1) % MAX;
                queue[rear] = item;
                if (front == -1)
                    front = 0;
            }
            break;

        case 2:
            if (front == -1 && rear == -1)
                printf("Queue is empty\n");
            else
            {
                item = queue[front];
                if (front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else
                    front = (front + 1) % MAX;
                printf("Removed element is %d \n", item);
            }
            break;

        case 3:
            printf("Queue contents are: ");
            for (i = front; i != rear; i = (i + 1) % MAX)
                printf(" %d ", queue[i]);
            printf(" %d ", queue[i]);
            printf("\n");
            break;

        case 4:
            exit(0);
        }
    } while (ch != 4);
    return 0;
}

