#include <stdio.h>
int main()
{

    int num ,i,price,book_id;
    char author[40];
    char book[40];
    FILE *fp;

    fp=fopen("books.txt","w");
    if(fp==NULL)
    {
        return 1;
        printf("'file is empty");
    }
    printf("enter the bumber of books:");
    scanf("%d",&num);
    for (i=0;i<num;i++)
    {
      printf("enter the book id:\n");
      scanf("%d",&book_id);
      printf("enter the book name:\n");
      scanf("%s",book);
      printf("enter the author name:\n");
      scanf("%s",author);
      printf("enter the price:\n");
      scanf("%d",&price);
      fprintf(fp," Book id:%d\n,book name:%s:\n,author:%s:\n,price:$%d:\n",book_id,book,author,price);
      




    }
    fclose(fp);
      printf("books details succesfully stored");
      return 0;
}