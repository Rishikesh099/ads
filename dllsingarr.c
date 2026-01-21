#include <stdio.h>

int array[100];
int head = -1;
int tail = -1;

int getfreeindex()
{
    for (int i = 0; i < 100; i += 3)
    {
        if (array[i] == -1 && array[i + 1] == -1 && array[i + 2] == -1)
            return i;
    }
    return -1;
}

void insertend(int x)
{
    int index = getfreeindex();
    if (index == -1)
    {
        printf("No free space to insert\n");
        return;
    }

    array[index + 1] = x;
    array[index + 2] = -1;

    if (head == -1)
    {
        head = index;
        array[index] = -1;
        tail = index;
    }
    else
    {
        int temp = head;
        while (array[temp + 2] != -1)
            temp = array[temp + 2];
        array[temp + 2] = index;
        array[index] = temp;
        tail = index;
    }
}

void deleteendd()
{
    int temp;
    if (head == -1)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        temp = head;
        if (array[temp + 2] == -1)
        {
            head = -1;
            tail = -1;
            array[temp] = -1;
            array[temp + 1] = -1;
            array[temp + 2] = -1;
            return;
        }
        else
        {
            while (array[temp + 2] != tail)
                temp = array[temp + 2];

            array[tail] = -1;
            array[tail + 1] = -1;
            array[tail + 2] = -1;

            array[temp + 2] = -1;
            tail = temp;
        }
    }
}

void display()
{
    if (head == -1)
    {
        printf("List is empty\n");
        return;
    }

    int temp = head;
    printf("Data: ");
    while (temp != -1)
    {
        if (array[temp + 1] != -1)
        {
            printf("%d ", array[temp + 1]);
        }
        temp = array[temp + 2];
    }
    printf("\n");
}

int main()
{
    for (int i = 0; i < 100; i += 3)
    {
        array[i] = -1;
        array[i + 1] = -1;
        array[i + 2] = -1;
    }

    int choice, val;
    while (1)
    {
        printf("\n1.Insert End\n2.Delete End\n3.display\n4.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Value to insert: ");
            scanf("%d", &val);
            insertend(val);
            display();
            break;
        case 2:
            deleteendd();
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
