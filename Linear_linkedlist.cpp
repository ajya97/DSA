#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
}
*start=NULL;

void create()
{
    struct node *temp,*ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter the number =");
    scanf("%d",&ptr->info);
    ptr->next= NULL;
    if(start==NULL)
        start=ptr;
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
    }
}

void display()
{
    struct node *temp;
    temp=start;
    while(temp->next!=NULL)
    {
        printf("%i\n",temp->info);
        temp=temp->next;
    }
    printf("%i",temp->info);
}

void insertfirst()
{
    struct node *info,*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the number =");
    scanf("%i",&newnode->info);
    newnode->next=NULL;
    if(start==NULL)
        start=newnode;
    else
    {
        newnode->next=start;
        start=newnode;
    }
}

void insertlast()
{
    struct node *ptr,*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the number = ");
    scanf("%i",&newnode->info);
    newnode->next=NULL;
    if(start==NULL)
        start=newnode;
    else
    {
        ptr=start;
        while(ptr->next)
            ptr=ptr->next;
        ptr->next=newnode;        
    }
}

void insertspecified()
{
    struct node *ptr,*newnode;
    int pos,i;
    printf("Enter the postion");
    scanf("%d",&pos);
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the number = ");
    scanf("%i",&newnode->info);
    newnode->next=NULL;
    ptr=start;
    for(i=0; i<pos; i++)
    {
        if(ptr->next=NULL)
        {
            printf("wrong choice");
            exit(0);
        } 
       ptr=ptr->next;
    }
    newnode->next=ptr->next;
        ptr->next=newnode;
}

int main()
{
    printf("start\n");
    create();
    create();
    create();
    create();
    create();
    printf("\nclose\n\n");
    display();
    insertspecified();
    display();
    insertlast();
    display();
    return 0;
}s