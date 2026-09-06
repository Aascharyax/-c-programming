#include <stdio.h>
struct student
{
    int id;
    char name [10];
    char adress [10];

}E[3];
int main()
{
    int i;
    printf("-enter the details of the students:\n");
    for (i=0;i<3;i++){

        printf("enter the name:\n");
        scanf("%s",E[i].name);
        printf("enter the id:\n");
        scanf("%d",&E[i].id);
        printf("enetr the adress:\n");
        scanf("%s",E[i].adress);
    }
    printf(" displaying the details");
    for (i=0;i<5;i++)
        {

            printf("name:%S \n id:%d \n adress:%s\n",E[i].name,E[i].id,E[i].adress);
            
        }
        return 0;
    
}