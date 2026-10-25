#include<stdio.h>
#include<string.h>
# define MAX 10
char stack[MAX][100];
int top =-1;

int visitWeb(char *web)
{
    if (top== MAX-1)
    {
        printf("stack is full");
        return 0;
    }
    else
    {
        top=top+1;
        strcpy(stack[top],web);
        return 1;
    }
}
int goback()
{
    if(top==-1)
    {
        printf("stack is Empty");
        return 0;
    }
    else
    {
        printf("%s\n",stack[top]);
        top=top-1;
        return 1;
    }
}

int currentpage()
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
void displayHistory()
{
    if(top==-1)
    {
        printf("Stack is Empty");

    }
    else
    {
        for(int     i=top; i>=0; i--)
        {
            printf("%s\n",stack[i]);
        }
    }
}

int main()
{
    int choice;
    char web[100];
    do
    {

        printf("\n--- Browser History ---\n");
        printf("1. Visit Website\n");
        printf("2. Go Back\n");
        printf("3. Current Page\n");
        printf("4. Display History\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter website: ");
            scanf("%99s", web);
            visitWeb(web);
            break;

        case 2:
            goback();
            break;

        case 3:
            currentpage();
            break;

        case 4:
            displayHistory();
            break;

        case 5:
            printf("Exiting Browser History...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    }
    while(choice != 5);

    return 0;
}



