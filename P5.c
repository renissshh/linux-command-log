#include<stdio.h>
struct e
{
    int empid;
    char pName[20];
    int month;
    float salary;
};

void calbil(struct e p)
{
    float commission;
    if(p.month < 25000)
    {
        commission = p.month * 0.02;
    }
    else if(p.month >= 25000 && p.month < 50000)
    {
        commission = p.month * 0.05;
    }
    else if(p.month >= 50000 && p.month < 100000)
    {
        commission = p.month * 0.08;
    }
    else if(p.month >= 100000)
    {
        commission = p.month * 0.10;
    }
    printf("Commission for this month's sales: %.2f\n", commission);
    float earning = commission + p.salary;
    printf(" 1.) Employee ID:%d .\n 2.) Salary : %2f. 3.)Number of Sales :%d .\n 4.)Commission Earned This Month Sale:%.2f .\n 5.)Total Eaning Included Salary:%.2f .\n",p.empid,p.salary,p.month,commission,earning);

}
int main()
{
    struct e emp[500];
    int n;
    printf("Enter the Number of details: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("Enter Employee ID :");
        scanf("%d",&emp[i].empid);
        printf("Enter Sales person Name  :");
        scanf("%s",emp[i].pName);
        printf("Enter The Salary :");
        scanf("%f",&emp[i].salary);
        printf("Enter Number of Sales in Month :");
        scanf("%d",&emp[i].month);
        calbil(emp[i]);

    }
}
