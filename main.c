#include"ListStack.h"

node* top = NULL;

int main(int argc,char** argv)
{

    push(&top,1);
    push(&top,2);
    push(&top,4);
    push(&top,5);
    
    pop(&top);
    print(&top);


    freeStack(&top);
    return 0;
}