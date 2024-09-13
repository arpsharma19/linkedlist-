#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
    int info;
    struct node *next;
};
node *insert(node *head, int v)
{
    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        head->info = v;
        head->next = NULL;
    }
    else
    {
        node *temp;
        temp = (node *)malloc(sizeof(node));
        temp->info = v;
        temp->next = head;
        head = temp;
    }
    return head;
}
void insertatend(node **head, node **last, int value)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->info = value;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
        *last = temp;
    }
    else
    {
        (*last)->next = temp;
        *last = temp;
    }
}
void insertatpos(node **head,int k,int value)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->info=value;
    if(k==0)
    {
        temp->next=*head;
        *head=temp;
        return ;
    }
    node *ptr=*head;
    for(int i=0;ptr!=NULL &&i<k-1;i++)
    {
        ptr=ptr->next;
    }
    if(ptr==NULL)
    {
        cout<<"Position not found:"<<endl;
    }
    temp->next=ptr->next;
    ptr->next=temp;

}
void display(node *head)
{
    while (head != NULL)
    {
        cout << head->info << endl;
        head = head->next;
    }
}
node *pop(node *head)
{
    if (head != NULL)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        return head;
    }
    else
    {
        cout << "List  is empty" << endl;
        return NULL;
    }
}
typedef struct node node;
int main()
{
    node *head = NULL;
    node *last = NULL;
    insertatend(&head, &last, 10);
    insertatend(&head, &last, 20);
    insertatend(&head, &last, 30);
    insertatend(&head, &last, 40);
    insertatend(&head, &last, 50);
    cout<<"Original list "<<endl;
    display(head);
    cout<<"After insertion at positions:"<<endl;
    insertatpos(&head,2,28);
    insertatpos(&head,0,22);
    display(head);
}