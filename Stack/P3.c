#include<stdio.h>
#include<string.h>
#define MAX 10

char stack[MAX];
int top=-1;


int is Matching(char open, char close)
{
    if(open =='(' && close ==')')
    {
        return 1;
    }
    if(open =='[' && close ==']')
    {
        return 1;
    }
    if(open =='{' && close =='}')
    {
        return 1;
    }
    return 0;
}
int isBalanced(char exp[])
{
    top = -1;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            top++;
            stack[top] = ch;
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (top == -1)
            {
                return 0;
            }

            if (isMatching(stack[top], ch) == 0)
            {
                return 0;
            }

            top--;
        }
    }

    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char exp[100];

    printf("Enter expression: ");
    scanf("%99s", exp);

    if (isBalanced(exp))
        printf("Balanced brackets\n");
    else
        printf("Not balanced\n");

    return 0;
}
