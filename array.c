//In this program using array's all function 
#include <stdio.h>
#include <stdlib.h>
int a[100],ub=0,lb=0,max=100;

void create()
{
    int i,n;
    printf("\nHow many values insert in array = ");
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        printf("\nEnter %d Element = ", ub+i+1);
        scanf("%d", &a[ub + i]);
    }
    ub += n;
}

void display()
{
    int i;
    if (lb == ub) {
        printf("\nArray is empty.\n");
        return;
    }
    for(i=lb; i<ub; i++){
        printf("\n%d value is = %d",i+1,a[i]);
    }
}

void insertfirst()
{
    int i,data;
    if(ub==max){
        printf("\nOverfllow");
    }
    else{
        printf("\nEnter the Value = ");
        scanf("%d",&data);
        for(i=ub;i>lb; i--){
            a[i]=a[i-1];
        }
        a[lb]=data;
        ub++;
    }
}

void insertlast()
{
    int i,data;
    if(ub==max){
        printf("\nOverfllow");
    }
    else{
        printf("\nEnter the Value = ");
        scanf("%d",&data);
        ub++;
        a[ub]=data;
    }
}

void insertspecified()
{
    int i,data,pos;
    if(ub==max){
        printf("\nOverfllow");
    }
    else{
        printf("\nEnter the position = ");
        scanf("%d",&pos);
        if (pos < 1 || pos > ub + 1) {
            printf("\nInvalid position\n");
            return;
        }
        printf("Enter the Value = ");
        scanf("%d",&data);
        for(i=ub; i>=pos-1;i--){
            a[i+1]=a[i];
        }
        a[pos-1]=data;
        ub++;
    }
}

void insertsortedarray()
{
    int i,data;
    if(ub==max){
        printf("\nOverfllow");
    }
    else{
        printf("\nEnter the Element");
        scanf("%d",&data);
        for(i=ub;a[i]>=data;i--){
                a[i+1]=a[i];
            }
        a[i+1]=data;
        ub++;
    }
}

void deletfirst()
{
    int i;
    if(ub==lb){
        printf("\nUnderflow");
    }
    else {
        for (int i = lb; i<ub-1; i++) {
            a[i] = a[i + 1];
        }
        ub--;
    }
}

void deletlast()
{
    if(ub==lb){
        printf("\nUnderflow");
    }
    else{
        a[ub]=0;
        ub--;
    }
}

void deletspecified()
{
    int i,data,temp=0;
    if(ub==lb){
        printf("\nUnderflow");
    }
    else{
        printf("\nEnter the Number = ");
        scanf("%d",&data);
        for(i=lb;i<=ub;i++){
            if(a[i]==data){
                temp=1;
            }
            if(temp==1){
                a[i]=a[i+1];
            }
        }
        ub--;
        if(temp==0){
                printf("\nYour element not in the array");
        }
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf(" \n\n*\nCreat a array = 1\nDisplay array = 2\nInsert element at first = 3\nInsert element at last = 4\nInsert element in given position = 5\nInsert element in sorted array = 6\nDelete First Element to the array = 7\nDelete Last Element to the array = 8\nDelete specified Element to the array = 9\nFor Exit = 10\n*\n");
        printf("\nEnter your choice = ");
        scanf("%d",&ch);
        if(ch==1)
            create();
        else if(ch==2)
            display();
        else if(ch==3)
            insertfirst();
        else if(ch==4)
            insertlast();
        else if(ch==5)
            insertspecified();
        else if(ch==6)
            insertsortedarray();
        else if(ch==7)
            deletfirst();
        else if(ch==8)
            deletlast();
        else if(ch==9)
            deletspecified();
        else if(ch==10)
            exit (0);
        else
            printf("wrong choice");
    }//ajeet
    return 0;
}