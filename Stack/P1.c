#include<stdio.h>
#include<string.h>
#define MAX 5

char stack[MAX][20];
int top = -1;

int push(char *vehicle)
{
    if(top==MAX -1)
    {
        printf("Stack is full");
        return 0;
    }

    else
    {
        top=top+1;
        strcpy(stack[top],vehicle);
        return 1;
    }


}
int pop()
{
    if(top==-1)
    {
        printf("Stack is underflow");
        return 0;
    }
    else
    {
        printf("%s\n",stack[top]);
        top=top-1;
        return 1;
    }
}

int peek()
{
    if(top==-1)
    {
        printf("Stack is Empty");
        return 0;
    }
    else
    {
        printf("%s\n",stack[top]);
        return 1;
    }
}
void display()
{
    if(top==-1)
    {
        printf("stack is empty");

    }
    else
    {
        for(int i=top; i>=0; i--)
        {
            printf("%s\n",stack[i]);

        }

    }
}
int search(char *vehicle)
{
    if(top==-1)
    {
        printf("stack is empty");
        return 0;
    }
    for(int i=top; i>=0; i--)
    {
        if(strcmp(stack[i],vehicle)==0)
        {
            printf("vehicle found");
            return 1;
        }
    }
    printf("\n not found");
    return 0;
}
int main()
{
    int choice;
    char vehicle[20];

    do
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Search\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Enter vehicle registration number: ");
            scanf("%19s", vehicle);
            push(vehicle);
            break;

        case 2:
             pop();
            break;

        case 3:
             peek();
            break;

        case 4:
             display();
             break;

        case 5:
            printf("Read vehicle registration number");
            scanf("%19s",vehicle);
            search(vehicle);
            break;

        case 6:
            printf("exit program\n");
            break;

        default:
            printf("invalid choice\n");
        }

    }
    while (choice !=6);

    return 0;
}
