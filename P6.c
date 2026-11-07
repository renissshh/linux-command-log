#include<stdio.h>
#include<string.h>

struct t
{
    int tNo;
    char pName[20];
    char source[20];
    char dest[20];
    float dist;
    char pCat[20];
};
void calbil(struct t a)
{
    float ticketFair=a.dist*2;
    printf("Ticket Fair : %2f\n",ticketFair);
    float finl;
    if(strcmp(a.pCat,"child")==0)
    {
         finl = ticketFair*0.50;
        printf("Based on category :%.2f\n",finl);
    }
    else if(strcmp(a.pCat,"senior")==0)
    {
         finl =ticketFair*0.30;
        printf("Based on category :%.2f",finl);
    }
    else if(strcmp(a.pCat,"regular")==0)
    {
         finl = ticketFair;
        printf("Based on category :%.2f",finl);
    }
    printf("Passenger Details : \n 1. %s. \n 2. %s. \n 3. %s. \n 4.%.2f \n",a.pName,a.source,a.dest,finl);

}
int main()
{
    struct t travel[500];
    int n;
    printf("Enter the Number Of Passenger : ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("Enter the Ticket Number:");
        scanf("%d",&travel[i].tNo);
        printf("Enter the Passenger Name:");
        scanf("%s",travel[i].pName);
        printf("Enter the Source :");
        scanf("%s",travel[i].source);
        printf("Enter the Destination :");
        scanf("%s",travel[i].dest);
        printf("Enter the Distance :");
        scanf("%f",&travel[i].dist);
        printf("Enter the Passenger Category:");
        scanf("%s",travel[i].pCat);
        calbil(travel[i]);
    }

}
