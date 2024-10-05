#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct node node;
void enqueue(node **f,node **r,int data){
    node *n=(node*)malloc(sizeof(node));
    if(n==NULL){
        printf("queue is full..");
    }
    else{
        n->data=data;
        n->next=NULL;
        if(*f==NULL){
            *f=*r=n;
        }
        else{
            (*r)->next=n;
            *r=n;
        }
    }
}
int dequeue(node **f){
    node *ptr=*f;
    int val=-1;
    if(*f==NULL){
        printf("queue is empty..\n");
    //    return val;
    }
    else{
        (*f)=(*f)->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}
int main(){
    //in the case of linked list the front and rear are the pointers which stores the address of nodes.
    node *front=NULL;//that's why I use the astrick in their declaration.
    node *rear=NULL;
    int res;
    node N;
    enqueue(&front,&rear,13);
    enqueue(&front,&rear,15);
    enqueue(&front,&rear,17);
    res=dequeue(&front);
    printf("%d \n",res);
    res=dequeue(&front);
    printf("%d ",res);
    return 0;
}