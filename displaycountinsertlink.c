#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}
    *first = NULL;
void create(int A[], int n)
{
    int i;
    struct node *t, *last;

    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i=1;i<n;i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t; // common step for making linked list
    }
}
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
 void count (struct node*p)
 {
    int l=0;
    int sum=0;    
        while(p!=0)
        {
        l++;
        sum=sum+p->data;
        p=p->next;
        
    }
    printf("\nsum is %d\n length is %d\n ",sum,l);
  
 }
 void insert(struct node* p,int data){
    struct node*ptr = (struct node *)malloc(sizeof(struct node));
    p->next=ptr;
    ptr->next=NULL;
    ptr->data=data;

 }

int main()
{
    
    int A[] = {3, 5, 7, 8, 9};  
    create(A,5);
    display(first);
    count(first);
    insert(first,4);
    display(first);
    return 0;
}