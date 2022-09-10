//
// Created by admin on 10.09.2022.
//

#ifndef STACKGL_LISTSTACK_H
#define STACKGL_LISTSTACK_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stddef.h>

typedef struct node
{
    int val;
    struct node* next;
} node;

void createStack(node**);
node* createNode();
void push(node** , int );
int pop(node** );
int getCapacity(node** );
void print(node** );
void freeStack(node** );
void addNodeIndex(node**, int ,node* );

extern node* top;

#endif STACKGL_LISTSTACK_H
