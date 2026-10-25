#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

int typeCharacter(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack is full\n");
        return 0;
    }

    top++;
    stack[top] = ch;

    return 1;
}
int undo()
{
    if (top == -1)
    {
        printf("Nothing to undo\n");
        return 0;
    }

    printf("undo character %c\n",stack[top]);
    top--;
    return 1;
}
void displayText()
{
    if (top == -1)
    {
        printf("Text is empty\n");
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf(" %c",stack[i]);
        }

        printf("\n");
    }
}
int main()
{
    int choice;
    char ch;

    do
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the charcter :");
            scanf(" %c",&ch);
            typeCharacter(ch);
            break;

        case 2:
            undo();
            break;

        case 3:
            displayText();
            break;

        case 4:
            printf("Exiting program\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    }
    while (choice != 4);

    return 0;
}
