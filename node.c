#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *insertBegin(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

struct Node *deleteFirstNode(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

void traverseLinkedList(struct Node *head)
{
    struct Node *current = head;
    printf("Linked List: ");
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int searchNode(struct Node *head, int target)
{
    struct Node *current = head;
    int position = 1;

    while (current != NULL)
    {
        if (current->data == target)
        {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}

int main()
{
    struct Node *head = NULL;
    int choice, data, position;

    while (1)
    {
        printf("1 Insert  begin\n");
        printf("2 Delete first node\n");
        printf("3 Traverse linked list\n");
        printf("4 Search a node\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            head = insertBegin(head, data);
            break;

        case 2:
            head = deleteFirstNode(head);
            break;

        case 3:
            traverseLinkedList(head);
            break;

        case 4:
            printf("Enter data to search: ");
            scanf("%d", &data);
            position = searchNode(head, data);
            if (position != -1)
            {
                printf("Node found at position %d\n", position);
            }
            else
            {
                printf("Node not found \n");
            }
            break;
        }
    }

    return 0;
}
