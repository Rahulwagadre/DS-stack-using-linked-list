#include<stdio.h>
#include<stdlib.h>

// Node initialization
typedef struct Node{
    int data;
    struct Node *next;
}Node;

// Top for stack
Node *top = NULL;

// Utility function for creating new node
Node* create_node(int data)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// checking underflow condition
void is_empty()
{
    if(top == NULL)
        printf("stack is empty...!\n\n");
    else
        printf("stack is not empty...!\n\n");
}

// Push function for inserting data
void push(int data)
{
    Node *temp = create_node(data);
    temp->next = top;
    top = temp;
}

// Pop function for deleting data
int pop()
{
    int res;
    Node *temp = NULL;
    if(top == NULL)
    {
        printf("Error : stack underflow!\n\n");
        return -1;
    }
    temp = top;
    res = top->data;
    top = top->next;
    free(temp);
    return res;
}

// get top element
int get_top()
{
    if(top == NULL)
        return -1;
    else
        return top->data;
}

// print stack
void show_stack()
{
    Node *ptr = top;
    printf("stack : ");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

// Main function
int main()
{
    printf("****   stack Implementation using linked list  ****\n");
    do{
        int choice,data;
        printf("\n\n_______________________________________________________________________________\n\n\n\n");
        printf("-> push : press 1\n-> pop : press 2\n-> get top element : press 3\n-> checking for underflow : press 4\n-> show list : press 5\n-> To end programm : press 6\n");
        printf("\n\nenter choice > ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\n\nEnter data > ");
                    scanf("%d",&data);
                    push(data);
                    break;
            case 2: printf("\n\nelement deleted > %d",pop());
                    break;
            case 3: printf("\n\ntop element > %d",get_top());
                    break;
            case 4: is_empty();
                    break;
            case 5: show_stack();
                    break;
            case 6: printf("\n\nprogram terminated successfully !\n\n");
                    printf("_______________________________________________________________________________\n\n\n");
                    exit(0);
            default: printf("\n\noops...! wrong input");

        }
    }while(1);
    return 0;
}
