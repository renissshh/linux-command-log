
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = value;
}

int pop()
{
    if (top == -1)
    {
        printf("Invalid Expression\n");
        return -1;
    }

    return stack[top--];
}

int evaluate(char exp[])
{
    int a, b, result;
    top = -1;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];

        if (isspace((unsigned char)ch))
            continue;

        if (isdigit((unsigned char)ch))
        {
            push(ch - '0');
        }
        else
        {
            if (top < 1)
            {
                printf("Invalid Expression\n");
                return -1;
            }

            b = pop();
            a = pop();

            switch (ch)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    if (b == 0)
                    {
                        printf("Division by zero\n");
                        return -1;
                    }
                    result = a / b;
                    break;

                default:
                    printf("Invalid Operator\n");
                    return -1;
            }

            push(result);
        }
    }

    if (top != 0)
    {
        printf("Invalid Expression\n");
        return -1;
    }

    return pop();
}

int main()
{
    char exp[MAX];
    int choice, result;

    do
    {
        printf("\n--- Postfix Evaluation Menu ---\n");
        printf("1. Evaluate Postfix Expression\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter postfix expression: ");
                scanf("%99s", exp);

                result = evaluate(exp);

                if (result != -1)
                    printf("Result = %d\n", result);

                break;

            case 2:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 2);

    return 0;
}
