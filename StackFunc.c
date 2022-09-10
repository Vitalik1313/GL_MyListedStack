//
// Created by admin on 10.09.2022.
//

#include"ListStack.h"


void createStack(node** top)
{
    top = malloc(sizeof(node));
    if(top == NULL)
    {
        fprintf(stderr,"Cannot allocate memory");
        return;
    }
    (*top)->next = NULL;
}

node* createNode()
{
    node* temp = malloc(sizeof(node));
    if(temp == NULL)
    {
        fprintf(stderr,"Cannot allocate memory");
        return NULL;
    }
    temp->next = NULL;
    return temp;
}

int getCapacity(node** top)
{
    node* temp = *top;
    int capacity=0;
    while(temp != NULL)
    {
        capacity++;
        temp=temp->next;
    }
    return capacity;
}


void push(node** top,int item)
{
    node* newNode=createNode();
    if(!newNode)
    {
        fprintf(stderr,"Cannot create new node\n");
        exit(EXIT_FAILURE);
    }
    newNode->val = item;
    if(!top){
        createStack(top);
        *top = newNode;
    }
    else
    {
        newNode->next = *top;
        *top = newNode;
    }
}

int pop(node** top)
{
    if(!top)
    {
        printf("Stack underflow");
        exit(EXIT_FAILURE);
    }
    int retVal = (*top)->val;
    node* temp = *top;
    *top = (*top)->next;

    free(temp);
    return retVal;
}

void print(node** top)
{
    node* temp = *top;
    while(temp!=NULL){
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
}

void freeStack(node** top)
{
    node* temp;
    while(top != NULL)
    {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}


void addNodeIndex(node** top,int index,node* newNode)
{
    if(index > getCapacity(top)){
        newNode->next = *top;
        *top=newNode;
        return;
    }
    node* temp = *top;
    int counter=0;
    while(counter != index - 1){
        temp = temp->next;
        counter++;
    }
    newNode->next=temp->next;
    temp->next = newNode;

}
