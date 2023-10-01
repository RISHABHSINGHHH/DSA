#include<stdio.h>
#include <stdlib.h>
int a[100];
int n=0;
void input()
{
	printf("Enter the size : \n");
	scanf("%d",&n);
	int i;
    printf("Enter the values : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display()
{
    printf("The array is : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void search()
{
    printf("Enter the value :\n");
    int x;
    scanf("%d",&x);
     for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            printf("The values was in %d",i+1);
        }
    }
}
void insert()
{
    if (n<100) {
        int val;
        printf("Enter the new value to insert: ");
        scanf("%d", &val);
        printf("Enter the position where the value should be inserted : ");
        int c;
        scanf("%d",&c);
        a[c]=val;
        printf("Value %d inserted at %d \n", val,c);
    } else {
        printf("Array is full\n");
    }
}
void delete()
{
    if (n>0) {
        int valu=a[n-1];
        n--;
        printf("Value %d deleted from the end\n",valu);
    } else {
        printf("Array is empty, cannot delete elements\n");
    }
}
int main()
{
    int a;
     while (1) {
        printf("\nMenu:\n");
        printf("1. Input values\n");
        printf("2. Display values\n");
        printf("3. Search for a value\n");
        printf("4. Insert a new value\n");
        printf("5. Delete a value from the end\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &a);
        switch (a) {
            case 1:
                input();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                delete();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}