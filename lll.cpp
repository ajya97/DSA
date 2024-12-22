#include<stdio.h>
#include<stdlib.h>
void create(int n);
struct node{
    int info;
    struct node *next;
};

struct node *start=NULL;
 
void generate()
{
    int i,n;
    printf("\n\nHow many element insert in list = ");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        create(i);
    }
}
 
void create(int n)
{
    struct node *temp,*ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter the %d number = ",n);
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
    int i=1;
    temp=start;
    if(temp==NULL){
        printf("\nEmpty");
        return;
    }
    while(temp->next!=NULL)
    {
        printf("\n%d Value = %i",i,temp->info);
        temp=temp->next;
        i+=1;
    }
    printf("\n%d Value = %i",i,temp->info);
}

void insertfirst()
{
    struct node *info,*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter the number = ");
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
    printf("\nEnter the number = ");
    scanf("%i",&newnode->info);
    newnode->next=NULL;
    if(start==NULL)
        start=newnode;
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=newnode;        
    }
}

void insertspecified()
{
    struct node *ptr,*newnode;
    int pos,i,no;
    printf("\nEnter the postion = ");
    scanf("%d",&pos);
    printf("\nEnter the number = ");
    scanf("%d",&no);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->info=no;
    newnode->next=NULL;
    if(pos == 1) {
        newnode->next = start;
        start = newnode;
        return;
    }

    ptr = start;
    for(i = 1; i < pos - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    if(ptr == NULL || ptr->next == NULL && pos != i + 1) {
        printf("\nInvalid position.\n");
        free(newnode);
        return;
    }
    newnode->next=ptr->next;
        ptr->next=newnode;
}

void deletf()
{
    if(start==NULL){
        printf("\nlist is empty");
    }
    else{
         start=start->next;
         printf("\nValue is deleted");
    }
}

void deletl()
{
    struct node *ptr1,*ptr2;
    if(start==NULL){
        printf("\nlist is empty");
    }
    else{
    ptr1=start;
    ptr2=start;
    while(ptr1->next!=NULL){
        ptr1=ptr1->next;
        if(ptr1->next==NULL){
            break;
        }
        else{
            ptr2=ptr2->next;
        }
    }
    ptr2->next=NULL;
    printf("\nValue is deleted");
    }
}

void deletpos()
{
    struct node *ptr1,*ptr2;
    int pos,i;
    if(start==NULL){
        printf("\nlist is empty");
    }
    else{
        ptr1=start;
        ptr2=start;
        printf("\nEnter the position of delet element = ");
        scanf("%d",&pos);
        for(i=1;i<pos; i++){
            ptr2=ptr2->next;
            if(i<pos-1){
                ptr1=ptr1->next;
            }
        }
        ptr1->next=ptr2->next;
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf(" \n\n*********\nCreat a list = 1\nDisplay list = 2\nInsert element in first = 3\nInsert element in last = 4\nInsert element in given position = 5\nDelete First Element to the list = 6\nDelete Last Element to the list = 7\nDelete given position Element to the list = 8\nFor Exit = 9\n**********\n");
        printf("\nEnter your choice = ");
        scanf("%d",&ch);
        if(ch==1)
            generate();
        else if(ch==2)
            display();
        else if(ch==3)
            insertfirst();
        else if(ch==4)
            insertlast();
        else if(ch==5)
            insertspecified();
        else if(ch==6)
            deletf();
        else if(ch==7)
            deletl();
        else if(ch==8)
            deletpos();
        else if(ch==9)
            exit (0);
        else
            printf("wrong choice");
    }
    return 0;
}