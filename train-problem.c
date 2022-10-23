#include<stdio.h>
#include<string.h>
struct train
{
    char name[50];
    int hrs, mins;
    char x[4];
};
int main()
{
    struct train arrv[5];
    int i;
    for (i=0;i<5;i++)
    {
        printf("\n name of train %d:", i+1);
        scanf("%s", arrv[i].name);
        printf("\n enter the time of arrival in hrs and mins: ");
        scanf("%d %d", &arrv[i].hrs, &arrv[i].mins);
        printf("enter AM or PM :");
        scanf("%s", arrv[i].x);
    }
    
    for (i=0;i<5;i++)
    {
        int result;
        result=strcmp(arrv[i].x,"PM");
        if (result==0)
        {
            printf("\n The time of arrival of %s", arrv[i].name);
            printf(" at time=>%d:%d ", arrv[i].hrs+12, arrv[i].mins);
            printf(" %s",arrv[i].x);
            
        }
        else
        {
            printf("\n The time of arrival of %s", arrv[i].name);
            printf(" at time:%d ", arrv[i].hrs);
            printf(": %d", arrv[i].mins);
            printf("%s",arrv[i].x);
          
        }

    }

    return 0;
}
