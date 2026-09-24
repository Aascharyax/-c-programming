#include <stdio.h>
struct employee
{

    int id,age,salary;
    char name[20];

}E[3];
int main()
{
    int i;
    FILE*fp;
    fp=fopen("employee.txt","w");
    if(fp==NULL)
    {

        printf("file not found");
        return 0;
    }

    printf("enter the details of the employee\n");
    for (i=0;i<3;i++)
    {

        printf("enter the id");
        scanf("%d",&E[i].id);
        printf("enter the name");
        scanf("%s",E[i].name);
        printf("enter the age");
        scanf("%d",&E[i].age);
        printf("enter the salary");
        scanf("%d",&E[i].salary);
        fprintf(fp,"%d %s %d %d",E[i].id,E[i].name,E[i].age,E[i].salary);

        
    }
    fclose(fp);

    fp=fopen("employee.txt","r");
    if(fp==NULL)
    {
        printf("file not found");
        return 1;
    }

    printf("displaying employees with salary between 25000 and 50000");
    i=0;//reseting the value of i
    while (fscanf(fp,"%d %s %d %d",&E[i].id,E[i].name,&E[i].age,&E[i].salary)==4)
    {
        if(E[i].salary>=25000 && E[i].salary<=50000)
        {
            printf("employee id:%d \n Name:%s \n Age:%d \n",E[i].id,E[i].name,E[i].age);

        }
        i++;


    }
    fclose(fp);
    return 0;
    

}